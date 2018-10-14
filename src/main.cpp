#include "snabl/env.hpp"
#include "snabl/repl.hpp"
#include "snackis/libs/db.hpp"
#include "snackis/std.hpp"

using namespace snackis;

int main(int argc, const char *argv[]) {
  snabl::Env env;
  env.add_lib<libs::DB>();
  env.use(snabl::Pos(-1, -1), env.sym("s.abc"));
  env.load("init.sl");
  snabl::repl(env, cin, cout);
  return 0;
}
