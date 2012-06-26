inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("Tunnel");
   set_long("In the tunnel into the mines.");

   add_exit("east","/domains/2.4.5/rooms/tunnel15.c");
   add_exit("west","/domains/2.4.5/rooms/tunnel9.c");
}