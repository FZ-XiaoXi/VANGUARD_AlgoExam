#include "expr.hpp"

#include <regex.h>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

enum {
  TK_NOTYPE = 256, TK_NUM = 1,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},
  {"\\+", '+'},
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"[0-9]+", TK_NUM},
  {"\\(", '('},
  {"\\)", ')'},
};

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};
static bool regex_initialized = false;
static bool eval_trace_enabled = true;

void set_eval_trace(bool enabled) {
  eval_trace_enabled = enabled;
}

void init_regex() {
  if (regex_initialized) {
    return;
  }

  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      std::cerr << "正则表达式编译失败：" << error_msg << "\n"
                << rules[i].regex << std::endl;
      exit(1);
    }
  }

  regex_initialized = true;
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536 / 2] = {};
static int nr_token = 0;
static const int TOKEN_CAPACITY = ARRLEN(tokens);
static bool eval_ok = true;

static bool make_token(const char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 &&
          pmatch.rm_so == 0) {
        int substr_len = pmatch.rm_eo;
        position += substr_len;

        if (rules[i].token_type != TK_NOTYPE && nr_token >= TOKEN_CAPACITY) {
          std::cerr << "token 数量超出上限" << std::endl;
          return false;
        }
        if (rules[i].token_type == TK_NUM &&
            substr_len >= (int)sizeof(tokens[0].str)) {
          std::cerr << "数字长度超出限制" << std::endl;
          return false;
        }

        switch (rules[i].token_type) {
        case TK_NOTYPE:
          break;
        case '+':
          tokens[nr_token].type = '+';
          strcpy(tokens[nr_token].str, "+");
          break;
        case '-':
          tokens[nr_token].type = '-';
          strcpy(tokens[nr_token].str, "-");
          break;
        case '*':
          tokens[nr_token].type = '*';
          strcpy(tokens[nr_token].str, "*");
          break;
        case '/':
          tokens[nr_token].type = '/';
          strcpy(tokens[nr_token].str, "/");
          break;
        case TK_NUM:
          memset(tokens[nr_token].str, 0, sizeof(tokens[nr_token].str));
          tokens[nr_token].type = TK_NUM;
          strncpy(tokens[nr_token].str, e + position - substr_len, substr_len);
          tokens[nr_token].str[31] = '\0';
          break;
        case '(':
          tokens[nr_token].type = '(';
          strcpy(tokens[nr_token].str, "(");
          break;
        case ')':
          tokens[nr_token].type = ')';
          strcpy(tokens[nr_token].str, ")");
          break;
        default:
          std::cerr << "未知的 token 类型：" << rules[i].token_type << std::endl;
        }

        if (rules[i].token_type != TK_NOTYPE) {
          nr_token++;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      std::cerr << "位置 " << position << " 处无法匹配输入：\n"
                << e << "\n"
                << std::string(position, ' ') << "^\n";
      return false;
    }
  }

  if (eval_trace_enabled) {
    std::cout << "匹配到 " << nr_token << " 个 token." << std::endl;
  }
  return true;
}

std::int32_t eval(int p, int q);

std::int32_t expr(const char *e, bool *success) {
  init_regex();

  if (success == nullptr || e == nullptr || !make_token(e) || nr_token == 0) {
    if (success != nullptr) {
      *success = false;
    }
    return 0;
  }

  eval_ok = true;

  std::int32_t out = eval(0, nr_token - 1);
  if (!eval_ok) {
    *success = false;
    return 0;
  }

  *success = true;
  return out;
}

bool check_parentheses(int p, int q) {
  if (p >= q || tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }

  int depth = 0;
  for (int i = p; i <= q; ++i) {
    if (tokens[i].type == '(') {
      ++depth;
    } else if (tokens[i].type == ')') {
      --depth;
      if (depth < 0) {
        return false;
      }
      if (depth == 0 && i < q) {
        return false;
      }
    }
  }

  return depth == 0;
}

std::int32_t eval(int p, int q) {
  if (eval_trace_enabled) {
    std::cout << "eval(" << p << ", " << q << ") : ";
    for (int i = p; i <= q; ++i) {
      std::cout << tokens[i].str << " ";
    }
    std::cout << std::endl;
  }

  if (p > q) {
    std::cerr << "表达式错误：表达式为空" << std::endl;
    eval_ok = false;
    return 0;
  } else if (p == q) {
    if (tokens[p].type != TK_NUM) {
      std::cerr << "表达式错误：缺少操作数" << std::endl;
      eval_ok = false;
      return 0;
    }

    std::int32_t out =
        static_cast<std::int32_t>(std::strtol(tokens[p].str, nullptr, 10));
    return out;
  } else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q);
  } else {
    int op = 0;
    int op_type = 0;
    int left = 0;
    int right = 0;
    int op_level = 3;

    for (int i = p; i <= q; ++i) {
      if (tokens[i].type == '(') {
        left++;
      } else if (tokens[i].type == ')') {
        right++;
      }

      if (right == left && i < q) {
        int current_level = 0;
        if (tokens[i].type == '+' || tokens[i].type == '-') {
          current_level = 1;
        } else if (tokens[i].type == '*' || tokens[i].type == '/') {
          current_level = 2;
        }

        if (current_level != 0 && current_level <= op_level) {
          op_type = tokens[i].type;
          op_level = current_level;
          op = i;
        }
      } else if (right > left) {
        std::cerr << "表达式错误：括号不匹配，右括号多于左括号" << std::endl;
        eval_ok = false;
        return 0;
      }
    }

    if (left != right) {
      std::cerr << "表达式错误：括号不匹配，左右括号数量不相等" << std::endl;
      eval_ok = false;
      return 0;
    }

    if (op_type == 0) {
      std::cerr << "表达式错误：缺少运算符" << std::endl;
      eval_ok = false;
      return 0;
    }

    std::int32_t val1 = eval(p, op - 1);
    if (!eval_ok) {
      return 0;
    }

    std::int32_t val2 = eval(op + 1, q);
    if (!eval_ok) {
      return 0;
    }

    switch (op_type) {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 + val2;
    case '/':
      if (val2 == 0 ) {
      std::cerr << "表达式错误：除数为0" << std::endl;  return false;}
      if (val1 == std::numeric_limits<std::int32_t>::min() && val2 == -1) {
        return std::numeric_limits<std::int32_t>::min();
      }
      return val1 / val2;
    default:
      eval_ok = false;
      std::cerr << "表达式错误：未知运算符：" << op_type << std::endl;
      return 0;
    }
  }
}
