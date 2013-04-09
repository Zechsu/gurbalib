#include "../../domain.h"

inherit "/std/room";

void setup(void) {
   add_area("2.4.5");

   set_short("A dimly lit forest");
   set_long("You are in part of a dimly lit forest.  " +
      "Trails lead north, south, east and west.");

   add_exit("north",DIR + "/rooms/south/sshore7.c");
   add_exit("south", DIR + "/rooms/south/sforst18.c");
   add_exit("east", DIR + "/rooms/south/sforst16.c");
   add_exit("west", DIR + "/rooms/south/sshore8.c");
}
