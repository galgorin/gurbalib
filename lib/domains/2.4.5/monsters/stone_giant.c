inherit MONSTER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_BLOCKEXITS;
#define DIR "/domains/2.4.5"

void setup() {
   object obj;

   set_name("giant");
   set_gender( "male" );
   add_adj("stone");
   set_in_room_desc("A stone giant");
   set_long("A huge marble skined hulking tower of a man.");
   set_race("giant");
   set_max_hp(300);
   set_level(15);
   set_aggressive(1);
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 50);
   set_skill("combat/defense", 100);

   obj = clone_object(DIR + "/obj/stone_sword");
   obj->setup();
   obj->move(this_object());
   do_wield(obj);
}

