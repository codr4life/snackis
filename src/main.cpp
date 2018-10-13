#include "snabl/env.hpp"
#include "snabl/repl.hpp"
#include "snackis/std.hpp"

using namespace snackis;

int main(int argc, const char *argv[]) {
  snabl::Env env;
  env.use(snabl::Pos(-1, -1), env.sym("s.abc"));
  snabl::repl(env, cin, cout);
  return 0;
}
