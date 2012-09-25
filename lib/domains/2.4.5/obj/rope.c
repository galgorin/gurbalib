inherit OBJECT;
string tied_to;
object tied_to_obj;

void setup(void) {
   set_id("rope");
   set_adj("old");
   set_gettable(1);
   set_value(15);
   set_weight(10);
}

string query_long() {
   if (tied_to) {
      return "An old rope tied to the " + tied_to + ".";
   }
   return "An old rope, you see nothing special about it.";
}

void set_tied(string str) {
   if (!str || (str == "")) {
      tied_to = "";
      set_in_room_desc("An old rope.");
   } else {
      tied_to = str;
      set_in_room_desc("An old rope tied to the " + tied_to + ".");
   }
}
