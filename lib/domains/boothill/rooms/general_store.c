inherit ROOM;

void setup(void) {
   add_area("boothill");

   set_brief("The general store");
   set_long("Still under contstruction.");

   set_exits(([
      "east" : "/domains/boothill/rooms/infront_store.c", 
   ]));

}