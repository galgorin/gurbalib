inherit ROOM;

void setup( void ) {
   set_brief( "%^MAGENTA%^North end of field.%^RESET%^" );
   set_long( "You are in a large open field, next to an old dead tree. " +
      " To the South you see a road leading to a city.  There is an odd " +
      "hole in a hill to the north.");
   set_exits( ([ 
      "south" : "/domains/required/rooms/start",
   ]) );
   set_objects( ([ 
      "/domains/newbie/objects/sign" : 1,
      "/domains/newbie/objects/tree" : 1,
   ]) );
   add_item("hole", "A funny hole in the ground.  You might be able to " +
      "enter it.");
  add_room_command("enter", "enter_hole");
}

int enter_hole(string arg) {
   string dest;

   if (arg == "hole") {
      if( this_player()->is_completed_quest("NewbieVille")) {
         write("The hole is too small for you to enter it.\n");
      } else {
         dest = "/domains/newbie/rooms/entrance";
         this_player()->query_environment()->tell_room( this_player(),
            capitalize(this_player()->query_name()) + " enters the hole.\n");
         write("You enter the hole.\n");
         this_player()->move(dest);
         this_player()->query_environment()->tell_room( this_player(),
            capitalize(this_player()->query_name()) + 
            " pops out of the hole.\n");
      }
      return 1;
   } else {
     write("Enter what?\n");  // maybe remove this line? 
                              // So you can try other enter commands...
     return 0;
   }
}
