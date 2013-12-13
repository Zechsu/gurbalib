#include "../domain.h"

inherit "/std/vendor";

void setup(void) {
   set_name("will");
   set_gender("male");
   add_id("shopkeeper", "merchant", "manager");
   set_short("Will, the manager of the general store");
   set_long("Will is a very stout individual.  It looks like he may " +
      "partake of granny's sweetrolls a little too much.");
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/sweetroll", 9);
   add_item(DIR + "/obj/lover_locket", 9);
}

