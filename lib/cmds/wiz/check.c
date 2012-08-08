mapping exits;

void usage() {
   write("Usage: check [-h] FILENAME\n");
   write("Check the supplied file, FILENAME.\n");
   write("If FILENAME is a directory check all files in that directory.\n");
   write("Options:\n");
   write("\t-h\tHelp, this usage message.\n");
   write("See also: update, clone\n");
}

void setup_exits() {
   exits["north"] = "south";
   exits["south"] =  "north";
   exits["east"] = "west";
   exits["west"] = "east";
   exits["up"] = "down";
   exits["down"] = "up";
   exits["northwest"] = "southeast";
   exits["southeast"] = "northwest";
   exits["northeast"] = "southwest";
   exits["southwest"] = "northeast";
}

string get_what(string str) {
   string path;

   path = this_player()->query_env("cwd");

   if (strlen(str) > 2) {
      if (str[strlen(str) - 2] == '.' && str[strlen(str) - 1] == 'c') {
	 // were good do nothing...
      } else {
	 str = str + ".c";
      }
   }

   path = normalize_path(str, path);

   return path;
}

void do_room_check(object obj) {
   write("Doing room check\n");
}

void do_monster_check(object obj) {
   write("Doing monster check\n");
}

void do_object_check(object obj) {
   write("Doing object check\n");
}

void do_check(string str) {
   string what;
   object obj;

   if (file_exists(str) == -1) {
      write("Checking directories unsupported currently: " + str + "\n");
   } else {
      what = get_what(str);
      if (file_exists(what) == 1) {

// XXX  obj = 

         if (obj) {
            if (obj->is_room()) {
               do_room_check(obj);
            } else if (obj->is_living()) {
               do_monster_check(obj);
            } else {
               do_object_check(obj);
            }
         } else {
            write("Unable to compile: " + str + "\n");
         }
      }
   }
}

void main(string str) {
   string *files;
   int x, max;

   if (!str || str == "") {
      usage();
      return;
   } else if (sscanf(str, "-%s", str)) {
      usage();
      return;
   }

   files = explode(str," ");
   if (!files) files = ([ str ]);
   max = sizeof(files);
   for(x=0;x<max;x++) {
      do_check(files[x]);
   }
}
