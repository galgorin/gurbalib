#include "../../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_short("The shore of Crescent Lake");
   set_long("You are standing on the shore of Crescent Lake, a beautiful " +
      "and clear lake.  Out in the centre of the lake stands the Isle " +
      "of the Magi.  Trails lead into the forest to the north and west.  " +
      "The shore of Crescent Lake continues northeast and southwest.");

   add_exit("north", DIR + "/rooms/south/sforst28.c");
   add_exit("west", DIR + "/rooms/south/sforst30.c");
   add_exit("northeast", DIR + "/rooms/south/sshore21.c");
   add_exit("southwest", DIR + "/rooms/south/sshore19.c");
}
