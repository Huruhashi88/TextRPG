#include <iostream>
#include <cstdlib>
using namespace std;

int progressOfTheDay = 0;
int MaxPOTD = 3;

int awareness = 0;
int MaxAwareness = 7;

int progressOfTheGame = 0;
int MaxPOTG = 4;
enum POTG
{
	NOMAL       = 0,//日常
	AWARENESS   = 1,//現状把握
	INVESTIGATE = 2,//原因特定
	SOLVING     = 3,//解決
	ENDING      = 4,//エンド
};


void TalkChange(int& POTG, int& POTD, int& awareness);
int ChoiceNum(int MaxChoiceNum);
void ShowScreen(int POTD, int awareness);
void PrologeOfTheDay(int POTG);
void HowToPlay();
void Solve(int& POTG, int& POTD, int& awareness);

int main()
{
	int choiceStart = 0;
	cout << "ゲームを開始しますか？" << endl
		<< "1:開始    " << "2:終了    " << "3:遊び方    " << endl;
	do
	{
		cin >> choiceStart;
	} while (choiceStart < 0 || choiceStart > 3);
	if (choiceStart == 2) return 0;
	else if (choiceStart == 3) HowToPlay();

	do
	{
		progressOfTheDay = MaxPOTD;
		PrologeOfTheDay(progressOfTheGame);

		do
		{
			ShowScreen(progressOfTheDay, awareness);
			TalkChange(progressOfTheGame, progressOfTheDay, awareness);
			if (progressOfTheDay <= 0) break;
		} while (true);
		cout << "もう夜だ、寝よう" << endl;
		system("pause");
		system("cls");
		if (progressOfTheGame == MaxPOTG) break;
	} while (true);
}

void TalkChange(int& POTG, int& POTD, int& awareness)
{
	int choice = 0;
	int MaxChoice = 0;
	
	switch (POTG)
	{
	case NOMAL://日常
		MaxChoice = 4 + awareness;
		cout << "さて、何をしようか" << endl
		     << "1:まずは顔でも洗おうか" << endl
			 << "2:食事をしようか" << endl
			 << "3:今日は何日だったっけ？" << endl
			 << "4:他に誰かいるか？" << endl;
		if (awareness >= 1) cout << "5:今日の用事は何かあったっけ？" << endl;
		if (awareness >= 2) cout << "6:外に出よう" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "顔を洗った" << endl;
			break;
		case 2:
			cout << "ご飯を食べた" << endl;
			break;
		case 3:
			cout << "今日は2月29日らしい" << endl
			 	 << "今年ってうるう年だったっけ" << endl;
			if (awareness == 0) awareness++;
			break;
		case 4:
			cout << "親はどちらとも仕事に行っているらしい" << endl
				 << "兄は...いつも通りだろうな" << endl;
			break;
		case 5:
			cout << "確か..." << endl
				 << "あれ？2月29日って仕事あったっけ？" << endl
				 << "いや、そもそも今年はうるう年じゃないような？" << endl;
			if (awareness <= 1) awareness++;
			break;
		case 6:
			cout << "玄関のドアが開かない!?" << endl
				 << "鍵はかかっていないみたいだけど、どうなっているんだ？" << endl;
			if (awareness <= 2) POTG++;
			break;
		}
		cout << endl;
		POTD--;
		break;

	case AWARENESS://現状把握
		MaxChoice = 5 + awareness - 2;
		cout << "よく考えてみると同じ日を繰り返していないか？" << endl
			 << "とにかく今何が起こっているのかを知ろう。" << endl
		     << "さて、何をしようか" << endl
			 << "1:日時を確認しよう" << endl
			 << "2:親との連絡をしてみよう" << endl
			 << "3:窓の外を見てみよう" << endl
			 << "4:寝る前の状況を思い出してみようか" << endl
			 << "5:食事をしよう" << endl;
		if (awareness >= 3) cout << "6:普段と違うところを探そう" << endl;
		if (awareness >= 4) cout << "7:兄と会話をしてみようか" << endl;
		if (awareness >= 5) cout << "8:今日、寝るふりをしてみよう" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "昨日はカレンダーだけを見ていたが、スマホでも日時を確認しておくべきだろう" << endl
				 << "カレンダーに印を付けていなかっただけかもしれない" << endl
				 << "と思ったが、そういうわけでもないらしい" << endl
				 << "やはり今日は2月29日のようだ" << endl;
			break;
		case 2:
			cout << "一応、親に確認を取っておくべきだろう" << endl
				 << "…連絡が取れない、どちらとも" << endl
				 << "仕事で忙しいのか？" << endl;
			break;
		case 3:
			cout << "見て見ぬふりをしようと思っていたけど、この際しょうがない" << endl
				 << "何かに塞がれているみたいだ" << endl
				 << "土のようではあるけれど、それにしては粘性があるように見える" << endl
				 << "…映像のようにも感じる" << endl;
			break;
		case 4:
			cout << "繰り返しのトリガーが寝ることなのかもしれない" << endl
				 << "…とはいえ別段変わったことはなかった気がする" << endl;
			break;
		case 5:
			cout << "腹が減っては戦ができぬ" << endl
				 << "一旦食事にしよう" << endl
				 << "!?" << endl
				 << "前回より食料が減っている？" << endl
				 << "単純な繰り返しっていうわけでもないらしい" << endl;
			if (awareness <= 2) awareness++;
			break;
		case 6:
			cout << "食料が減っているなら他にも何か変化があるかもしれない" << endl
				 << "洗剤などの生活用品が減っている" << endl
				 << "それぐらいのようだ" << endl
				 << "ただ、分かったことがある" << endl
				 << "生活感があることだ" << endl
				 << "ループというより、似たような日々を繰り返しているようだ" << endl;
			if (awareness <= 3) awareness++;
			break;
		case 7:
			cout << "スマホの日時が変わらない" << endl
				 << "身近な人間で、こんな芸当ができるのはあいつだけだろう" << endl
				 << "部屋の前まで移動した" << endl
				 << "自分:「なあ」" << endl
				 << "兄　:「...」" << endl
				 << "自分:「単刀直入に聞くけど、スマホの時間を変えてるのお前だよな？」" << endl
				 << "兄　:「...」" << endl
				 << "自分:「なぜこんなことをしてる？」" << endl
				 << "兄　:「...」" << endl
				 << "自分:「何が目的だ？」" << endl
				 << "兄　:「...」" << endl
				 << "自分:「いつもみたいにだんまりか？」" << endl
				 << "兄　:「なぜだと思う？」" << endl
				 << "自分:「は？こっちが聞いてるんだが」" << endl
			 	 << "兄　:「俺に聞くな、あくまで協力してるだけだからな」" << endl
			 	 << "これ以上は何も話してくれなかった" << endl;
			if (awareness <= 4) awareness++;
			break;
		case 8:
			cout << "寝ている間に何かされているのであれば" << endl
				<< "寝なければいいだけの話" << endl
				<< "一応寝たふりをしておこう" << endl
				<< endl
				<< "結果から言おう" << endl
				<< "記憶がない" << endl
				<< "痛みを感じたのは覚えている" << endl;
			POTD = 1;
			if (awareness <= 5) POTG++;
			break;
		}
		cout << endl;
		POTD--;
		break;
	case INVESTIGATE://原因特定
		MaxChoice = 1 + awareness - 5;
		cout << "さあ、何から始めようか" << endl
			 << "1:もう一度親に電話をしてみよう" << endl;
		if (awareness >= 6) cout << "2:もう一度兄と話をしようか" << endl;
		if (awareness >= 7) cout << "3:原因を特定しよう" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "もう一度親に連絡を取ろう、何か分かるかもしれない" << endl
				<< "…変わらず連絡は取れない" << endl
				<< "連絡が取れない状況なのか、それとも連絡を控えているのか" << endl;
			if (awareness <= 5) awareness++;
			break;
		case 2:
			cout << "やはり兄に聞くしかないのか" << endl
				<< "…結局何も話してくれなかった" << endl;
			if (awareness <= 6) awareness++;
			break;
		case 3:
			cout << "とはいえこの状況からどう判断するべきなのか" << endl
				<< "一旦情報を整理しよう" << endl
				<< "今日は2月29日、うるう年、ただしこれが本当の日時なのか分からない、これは必要ない情報か？" << endl
				<< "窓の外は土のような何かで塞がれている、これは何だろう" << endl
				<< "食料が減っている、生活感がある、ループではなく似たような日々の繰り返し" << endl
				<< "外には出られない、鍵はかかっていない" << endl
				<< "親は外出している、連絡は取れない" << endl
				<< "兄は原因ではない、「協力しているだけ」らしい" << endl
				<< "寝る直前感じた痛みは何によるものだったのだろうか" << endl
				<< "この少ない情報で分かることなんてあるのだろうか" << endl;
			if (awareness <= 7) POTG++;
			POTD = 1;
			//awareness = 0;
			break;
		}
		cout << endl;
		POTD--;
		break;
	case SOLVING://解決
		cout << "ここからは情報をもとに推理するターン" << endl
			<< "正しい推理を選ぶ、間違った選択肢を数回選ぶと一日の初めからやり直しになる" << endl;
		Solve(POTG, POTD, awareness);
		break;
	case ENDING://エンド
		MaxChoice = 1;
		POTD = 0;
		cout << "さて、何をしようか" << endl
			<< "1:日時を確認する" << endl;
		ChoiceNum(MaxChoice);
		cout << "今日は3月1日らしい" << endl
			 << endl
			 << "ゲームクリア" << endl
			 << endl;
		break;
	}
}

void Solve(int& POTG, int& POTD, int& awareness)
{
	awareness = 0;
	do
	{
		system("cls");
		ShowScreen(progressOfTheDay, awareness);
		switch (awareness)
		{
		case 1:
			cout << "まず今日は2月29日なのだろうか" << endl
				 << "1:そうだ" << endl 
				 << "2:違う" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "食料が減っていたり、生活用品が減っていたり" << endl
					 << "時間は確実に経過している" << endl
					 << "そもそも、同じ時間を繰り返すなどあり得ないことだからだ" << endl
					 << endl;
			}
			else 
			{ 
				POTD--; 
				cout << "違う" << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "窓の外の景色について" << endl
				 << "1:映像による出まかせだ" << endl
				 << "2:外は土のような物体で塞がれている" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "兄ならそれぐらいこなせるだろう" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "違う" << endl;
			}
			system("pause");
			break;
		case 3:
			cout << "玄関のドアは鍵がかかっていないにもかかわらず、開かない" << endl
				 << "1:本当にドアは開かないのだろうか、" << endl
				 << "2:魔法でも使っているのだろう" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "解決になっていない。ただ、" << endl
					 << "鍵がかかっていないのに開かないなんてことはあり得ない。" << endl
					 << "親が外出をしている以上、ドアは開くだろう" << endl
					 << "ドアが開かないと勘違い、そう思わされているのではないか" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "違う" << endl;
			}
			system("pause");
			break;
		case 4:
			cout << "親は外出している、連絡が取れないのはなぜか" << endl
				 << "1:忘れているだけで、親はもういないのではないか" << endl
				 << "2:本当に親に連絡したのだろうか" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "こちらも解決していない。ただやはり、" << endl
					 << "一日を繰り返していると思わされていた前例がある" << endl
					 << "連絡したと思わされているのではないか" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "違う" << endl;
			}
			system("pause");
			break;
		case 5:
			cout << "この間寝たふりをしようとした際の痛みは何だろうか" << endl
				 << "1:誰かに眠らされる薬品でも注入されたのではないか" << endl
				 << "2:誰かから受けた痛みではないのではないか" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "寝る直前だ" << endl
					 << "いくら強い痛みだったとしても、気絶でもしない限り、痛みで寝れないだろう" << endl
					 << "もし気絶するほどの痛みであれば、血が出ていてもおかしくはない" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "違う" << endl;
			}
			system("pause");
			break;
		case 7:
			cout << "だとしたらこの繰り返しの原因は誰なのだろう" << endl
				 << "1:もしかして自分なのではないだろうか" << endl
				 << "2:親はいない、兄は協力者、他の第三者が存在するのではないか" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "ただ自分で自分が一日を繰り返しているという思い込みをしているだけなのではないか" << endl
					 << "そうすれば、雑ではあるが合点がいく" << endl
					 << "解決方法は…自覚するしかないだろう" << endl
					 << "時間を" << endl
					 << endl;
				POTG++;
			}
			else
			{
				POTD = 0;
				cout << "違う" << endl;
			}
			system("pause");
			break;
		}
		if(awareness <= 7) awareness++;
	} while (POTD > 0 && awareness <= 7);
	POTD = 1;
}

int ChoiceNum(int MaxChoiceNum)
{
	int choice = 0;
	do
	{
		cin >> choice;
	} while (choice <= 0 || choice > MaxChoiceNum);

	system("cls");

	return choice;
}

void PrologeOfTheDay(int POTG)
{
	switch (POTG)
	{
		case NOMAL:
			cout << "何の変哲もない、いつもの朝" << endl;
			break;
		case AWARENESS:
			cout << "いつもの朝、ただ少しだけ違和感が" << endl;
			break;
		case INVESTIGATE:
			cout << "また繰り返す、もう解決に向かう時期だろう" << endl;
			break;
		case SOLVING:
			cout << "時は戻らない、そろそろ終わらせる時間だ" << endl;
			break;
		case ENDING:
			cout << "何の変哲もない、いつもの朝" << endl;
			break;
	}
	cout << endl;
}

void ShowScreen(int POTD, int awareness)
{
	cout << "時間" << POTD << endl
		<< "自覚度" << awareness << "/" << MaxAwareness << endl
		<< endl;

}

void HowToPlay()
{
	int choice = 0;
	bool endJudge = true;
	do
	{
		system("cls");
		cout << "どの説明が聞きたいですか？" << endl
			<< "1:ゲームの内容" << "2:画面の説明"  << "3:終了" << endl;
		do
		{
			cin >> choice;
		} while (choice < 1 || choice > 3);
		switch (choice)
		{
		case 1:
			cout << "目標は繰り返す日々からの脱出" << endl
				<< "1日が始まったら、自分の行動を選択肢から選び、少しずつ繰り返しの原因を見つけ、脱出を目指します" << endl
				<< "行動毎に時間が進み、一定の行動で「自覚度」が上がっていきます" << endl
				<< "最初の目的は自覚度を上げ、ゲームを進行させること" << endl
				<< "終盤、内容に関する軽いゲームがあります。" << endl
				<< "ただし無理やりの決めつけが多いので覚えて答えるようなゲームになっています。" << endl
				<< endl;

			system("pause");
			break;
		case 2:
			cout << "時間" << 3 << "    <-これは一日に行動できる回数" << endl
				<< "自覚度" << 1 << "/" << MaxAwareness << "    <-これはゲームの進行度" << endl
				<< "自覚度によって、ゲームの進行度合いを知ることができます。" << endl
				<< endl;

			system("pause");
			break;
		case 3:
			endJudge = false;
			break;
		}
	} while (endJudge);
}
