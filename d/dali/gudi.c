//Cracked by Kafei
// Room: /dali/gudi.c
// AceP

inherit ROOM;

int do_eat(string);
int do_drink(string);
int do_sit();
int do_push(string);
int do_enter(string);

void create()
{
	set("short", "�ȵ�");
	set("long", @LONG
��վ�ڹȵף���Ŀһ�������ɵú���һ���ʡ�ֻ�����ɽ���ϵĴ��ٲ�(pubu)
���������գ��������£�����һ���峺�ޱȵĴ��(lake)֮�С��ٲ�ע�봦��ˮ��
�ڣ�ֻ����ٲ�ʮ���ɣ���ˮ��һƽ�羵����������һ�Բ軨�����ҡҷ���ˡ���
�о����ĵģ���˵�˼���������Ҳ�ް�㣬Ψ�������أ�ң��ͺ����±���һ��
��С���������в���Ұ��(yeguo)��
LONG );

	set("item_desc", ([
		"lake"   :
"�������Բ֮�Σ���벿���ڻ���֮�У������������������ͱ�(qiaobi)�����޳�·��\n"
"���ٲ�����ע�룬��ˮȴ�����磬��������йˮ֮����\n",
		"qiaobi" :
"�������ıڣ����ֳ�����������ɽ·�Ƚ���б��������������ֱ��ֱ�¾����޷���Ԯ��\n"
"�������£�������ȣ��������������ѣ�������ȥ�������������͡�\n",
		"pubu"   :
"�۹������ٲ����¶��ϵĿ�ȥ��ֻ���ٲ�֮ʯһƬʯ�ڹ�����������ǧ����ǰ�ٲ���\n"
"���ո��󣬲�֪������������ĳ弤ĥϴ���������ʯ��ĥ�����ƽ���������ٲ�ˮ��\n"
"���٣���¶������Ƭ����������������ʯ�ڳ�����\n",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
	add_action("do_eat", "eat");
	add_action("do_sit", "sit");
	add_action("do_push", "push");
	add_action("do_enter", "enter");
}

int do_drink(string arg)
{
	object me;
	me=this_player();

	if (arg=="lake") {
		tell_object(me,"���ߵ����ߣ����𼸿ں�ˮ���ˣ���������������쳣��һ��������ˮ��ֱͨ�븹�С�\n");
		me->set("jing", me->query("max_jing"));
		set("drunk",1);
		return 1;
	}
	return 0;
}

int do_eat(string arg)
{
	object me;
	me=this_player();

	if (arg=="yeguo" && query("drunk")) {
		tell_object(me,"���߹�ȥժ�˼���Ұ�����ˣ��о�ζ���ü��ˡ�\n");
		me->set("qi", me->query("max_qi"));
		set("ate", 1);
		delete("drunk");
		return 1;
	}
	return 0;
}

int do_sit()
{
	object me;
	me=this_player();

	if (query("ate")) {
		tell_object(me,
"�㱧ϥ���£����ۺ���ɽɫ���������������ޣ�����ʱ��֮����һƳ�ۼ䣬������\n"
"��ʯ�������в�ɫ��������Ȼ��һ�ѽ���Ӱ�ӣ���Ӱ�峺�쳣�����������������⣬\n"
"���֣���һ�����Ƶ�ʮ��������Ӱ�и������ʺ�һ����ι���˸���������߲�����\n"
"����棬վ������ϸ�۲죬���ֱ��ϵĽ�Ӱбָ�򱱣������׼��һ�����ʯ����\n"
"�ߵ���ʯ��ǰ������ȥ������΢΢ҡ�Σ���ʯ�����أ����������Ʋ��������ֵ���\n"
"ʯ����ȥ��ԭ����ʯ���������һ��Сʯ֮�ϣ�Ҳ��֪��������������Ϊ��\n\n");
		delete("ate");
		set("found",1);
		return 1;
	}
	return 0;
}

int do_push(string arg)
{
	object me;
	me=this_player();

	if (arg=="right" && query("found")) {
		tell_object(me,
"��˫��������ʯ�Ҳ࣬��ʯ�ֻ���һ�£���һ�ξͻأ�ʯ�׷����������ѵ�������\n"
"�����Ѵ�С��ʯ�������ȫ����ȥ��������ɳ�����ƣ�������ʯ����ת��������һ\n"
"�ȴ������ƣ�ת��һ�룬����ʯ��¶��һ�����ߴ�Ķ��ڡ�\n");
		delete("found");
		set("opened",1);
		return 1;
	}
	return 0;
}

int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg=="dong" && query("opened")) 
	{
		tell_object(me,
"�������߽���ȥ���ߵ�ʮ�ಽ���������޹�����ÿһ�������Թ���ʵ����������ƽ\n"
"����������ʯ������һ����ֻ�ǵ�·������б��ͻȻ֮�䣬��������һ��������\n"
"��Բ�һ��֮�£���Բ�ﵱ��һ�£���������������������ԭ���Ǹ��Ż�������\n"
"�������ţ�������ͭ�����ɣ����ǳ��أ������沢δ���ϣ�һʹ�������žͻ�����\n"
"���ˣ����˽�ȥ����Ȼ�������κ����£�ֻ��ù�����أ��ƺ�����û����ס������\n"
"��ǰ����ͷײ����ʲô������ԭ������һ���ţ�������ʹ�������Ŵ򿪣���ǰ��Ȼ\n"
"��������������������һ��ʯ�ҡ�\n");
		me->move(__DIR__"shishi1");
		delete("opened");
		return 1;
	}
	return 0;
}