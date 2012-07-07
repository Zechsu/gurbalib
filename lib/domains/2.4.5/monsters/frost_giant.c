inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_BLOCKEXITS;
#define DIR "/domains/2.4.5"

void setup() {
   object obj;

   set_name("giant");
   set_gender( "male" );
   add_adj("frost");
   set_in_room_desc("A frost giant");
   set_long("A frozen mass of muscle.  You really do not want to mess " +
      "with this giant.");
   set_race("giant");
   set_level(15);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/frost_sword");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

