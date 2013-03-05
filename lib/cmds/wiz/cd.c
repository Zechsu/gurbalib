void usage() {
   string *lines;

   lines = ({ "Usage: cd [-h] [dir]" });
   lines += ({ " " });
   lines += ({ "Change the current working directory(cwd) to [dir]." });
   lines += ({ "If [dir] is not given, the working directory is set to the " +
      "wizards home directory." });
   lines += ({ " " });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "cd /cmds         Change cwd to the /cmds directory." });
   lines += ({ "cd ..            Move up one directory." });
   lines += ({ "cd               Change cwd to /wiz/(username)." });
   lines += ({ "See also:" });
   lines += ({ "\tbrowse, cat, cp, diff, edit, ls, more, mkdir, pwd, " +
      "rm, tail" });

   this_player()->more(lines);
}

#define MODE_READ 0

void main(string arg) {
   int tmp;

   if (!arg || arg == "") {
      arg = "/wiz/" + this_player()->query_name();
   } else if (sscanf(arg, "-%s", arg)) {
      usage();
      return;
   }

   arg = normalize_path(arg, this_player()->query_env("cwd"));

   if (!arg || arg == "") {
      write("Access denied.\n");
      return;
   }

   if (strlen(arg) > 1 && arg[strlen(arg) - 1] == '/') {
      arg = arg[..strlen(arg) - 2];
   }

   tmp = file_exists(arg);

   if (tmp == 1) {
      write("Can not cd to a file: " + arg + "\n");
      return;
   } else if (tmp != -1) {
      write("Error " + tmp + ": Dir not found: " + arg + "\n");
      return;
   }

   if (!valid(arg, MODE_READ)) {
      write("Access denied.\n");
      return;
   }

   this_player()->set_env("cwd", arg);
   this_player()->set_env("pwd", this_player()->query_env("cwd"));
   write("%^BOLD%^" + this_player()->query_env("cwd") + "%^RESET%^\n");
}
