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
	NOMAL       = 0,//����
	AWARENESS   = 1,//����c��
	INVESTIGATE = 2,//��������
	SOLVING     = 3,//����
	ENDING      = 4,//�G���h
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
	cout << "�Q�[�����J�n���܂����H" << endl
		<< "1:�J�n    " << "2:�I��    " << "3:�V�ѕ�    " << endl;
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
		cout << "�����邾�A�Q�悤" << endl;
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
	case NOMAL://����
		MaxChoice = 4 + awareness;
		cout << "���āA�������悤��" << endl
		     << "1:�܂��͊�ł��􂨂���" << endl
			 << "2:�H�������悤��" << endl
			 << "3:�����͉��������������H" << endl
			 << "4:���ɒN�����邩�H" << endl;
		if (awareness >= 1) cout << "5:�����̗p���͉��������������H" << endl;
		if (awareness >= 2) cout << "6:�O�ɏo�悤" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "�������" << endl;
			break;
		case 2:
			cout << "���т�H�ׂ�" << endl;
			break;
		case 3:
			cout << "������2��29���炵��" << endl
			 	 << "���N���Ă��邤�N����������" << endl;
			if (awareness == 0) awareness++;
			break;
		case 4:
			cout << "�e�͂ǂ���Ƃ��d���ɍs���Ă���炵��" << endl
				 << "�Z��...�����ʂ肾�낤��" << endl;
			break;
		case 5:
			cout << "�m��..." << endl
				 << "����H2��29�����Ďd�������������H" << endl
				 << "����A�����������N�͂��邤�N����Ȃ��悤�ȁH" << endl;
			if (awareness <= 1) awareness++;
			break;
		case 6:
			cout << "���ւ̃h�A���J���Ȃ�!?" << endl
				 << "���͂������Ă��Ȃ��݂��������ǁA�ǂ��Ȃ��Ă���񂾁H" << endl;
			if (awareness <= 2) POTG++;
			break;
		}
		cout << endl;
		POTD--;
		break;

	case AWARENESS://����c��
		MaxChoice = 5 + awareness - 2;
		cout << "�悭�l���Ă݂�Ɠ��������J��Ԃ��Ă��Ȃ����H" << endl
			 << "�Ƃɂ����������N�����Ă���̂���m�낤�B" << endl
		     << "���āA�������悤��" << endl
			 << "1:�������m�F���悤" << endl
			 << "2:�e�Ƃ̘A�������Ă݂悤" << endl
			 << "3:���̊O�����Ă݂悤" << endl
			 << "4:�Q��O�̏󋵂��v���o���Ă݂悤��" << endl
			 << "5:�H�������悤" << endl;
		if (awareness >= 3) cout << "6:���i�ƈႤ�Ƃ����T����" << endl;
		if (awareness >= 4) cout << "7:�Z�Ɖ�b�����Ă݂悤��" << endl;
		if (awareness >= 5) cout << "8:�����A�Q��ӂ�����Ă݂悤" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "����̓J�����_�[���������Ă������A�X�}�z�ł��������m�F���Ă����ׂ����낤" << endl
				 << "�J�����_�[�Ɉ��t���Ă��Ȃ�����������������Ȃ�" << endl
				 << "�Ǝv�������A���������킯�ł��Ȃ��炵��" << endl
				 << "��͂荡����2��29���̂悤��" << endl;
			break;
		case 2:
			cout << "�ꉞ�A�e�Ɋm�F������Ă����ׂ����낤" << endl
				 << "�c�A�������Ȃ��A�ǂ���Ƃ�" << endl
				 << "�d���ŖZ�����̂��H" << endl;
			break;
		case 3:
			cout << "���Č��ʂӂ�����悤�Ǝv���Ă������ǁA���̍ۂ��傤���Ȃ�" << endl
				 << "�����ɍǂ���Ă���݂�����" << endl
				 << "�y�̂悤�ł͂��邯��ǁA����ɂ��Ă͔S��������悤�Ɍ�����" << endl
				 << "�c�f���̂悤�ɂ�������" << endl;
			break;
		case 4:
			cout << "�J��Ԃ��̃g���K�[���Q�邱�ƂȂ̂�������Ȃ�" << endl
				 << "�c�Ƃ͂����ʒi�ς�������Ƃ͂Ȃ������C������" << endl;
			break;
		case 5:
			cout << "���������Ă͐킪�ł���" << endl
				 << "��U�H���ɂ��悤" << endl
				 << "!?" << endl
				 << "�O����H���������Ă���H" << endl
				 << "�P���ȌJ��Ԃ����Ă����킯�ł��Ȃ��炵��" << endl;
			if (awareness <= 2) awareness++;
			break;
		case 6:
			cout << "�H���������Ă���Ȃ瑼�ɂ������ω������邩������Ȃ�" << endl
				 << "��܂Ȃǂ̐����p�i�������Ă���" << endl
				 << "���ꂮ�炢�̂悤��" << endl
				 << "�����A�����������Ƃ�����" << endl
				 << "�����������邱�Ƃ�" << endl
				 << "���[�v�Ƃ������A�����悤�ȓ��X���J��Ԃ��Ă���悤��" << endl;
			if (awareness <= 3) awareness++;
			break;
		case 7:
			cout << "�X�}�z�̓������ς��Ȃ�" << endl
				 << "�g�߂Ȑl�ԂŁA����Ȍ|�����ł���̂͂����������낤" << endl
				 << "�����̑O�܂ňړ�����" << endl
				 << "����:�u�Ȃ��v" << endl
				 << "�Z�@:�u...�v" << endl
				 << "����:�u�P�������ɕ������ǁA�X�}�z�̎��Ԃ�ς��Ă�̂��O����ȁH�v" << endl
				 << "�Z�@:�u...�v" << endl
				 << "����:�u�Ȃ�����Ȃ��Ƃ����Ă�H�v" << endl
				 << "�Z�@:�u...�v" << endl
				 << "����:�u�����ړI���H�v" << endl
				 << "�Z�@:�u...�v" << endl
				 << "����:�u�����݂����ɂ���܂肩�H�v" << endl
				 << "�Z�@:�u�Ȃ����Ǝv���H�v" << endl
				 << "����:�u�́H�������������Ă�񂾂��v" << endl
			 	 << "�Z�@:�u���ɕ����ȁA�����܂ŋ��͂��Ă邾��������ȁv" << endl
			 	 << "����ȏ�͉����b���Ă���Ȃ�����" << endl;
			if (awareness <= 4) awareness++;
			break;
		case 8:
			cout << "�Q�Ă���Ԃɉ�������Ă���̂ł����" << endl
				<< "�Q�Ȃ���΂��������̘b" << endl
				<< "�ꉞ�Q���ӂ�����Ă�����" << endl
				<< endl
				<< "���ʂ��猾����" << endl
				<< "�L�����Ȃ�" << endl
				<< "�ɂ݂��������̂͊o���Ă���" << endl;
			POTD = 1;
			if (awareness <= 5) POTG++;
			break;
		}
		cout << endl;
		POTD--;
		break;
	case INVESTIGATE://��������
		MaxChoice = 1 + awareness - 5;
		cout << "�����A������n�߂悤��" << endl
			 << "1:������x�e�ɓd�b�����Ă݂悤" << endl;
		if (awareness >= 6) cout << "2:������x�Z�Ƙb�����悤��" << endl;
		if (awareness >= 7) cout << "3:��������肵�悤" << endl;

		switch (ChoiceNum(MaxChoice))
		{
		case 1:
			cout << "������x�e�ɘA������낤�A���������邩������Ȃ�" << endl
				<< "�c�ς�炸�A���͎��Ȃ�" << endl
				<< "�A�������Ȃ��󋵂Ȃ̂��A����Ƃ��A�����T���Ă���̂�" << endl;
			if (awareness <= 5) awareness++;
			break;
		case 2:
			cout << "��͂�Z�ɕ��������Ȃ��̂�" << endl
				<< "�c���ǉ����b���Ă���Ȃ�����" << endl;
			if (awareness <= 6) awareness++;
			break;
		case 3:
			cout << "�Ƃ͂������̏󋵂���ǂ����f����ׂ��Ȃ̂�" << endl
				<< "��U���𐮗����悤" << endl
				<< "������2��29���A���邤�N�A���������ꂪ�{���̓����Ȃ̂�������Ȃ��A����͕K�v�Ȃ���񂩁H" << endl
				<< "���̊O�͓y�̂悤�ȉ����ōǂ���Ă���A����͉����낤" << endl
				<< "�H���������Ă���A������������A���[�v�ł͂Ȃ������悤�ȓ��X�̌J��Ԃ�" << endl
				<< "�O�ɂ͏o���Ȃ��A���͂������Ă��Ȃ�" << endl
				<< "�e�͊O�o���Ă���A�A���͎��Ȃ�" << endl
				<< "�Z�͌����ł͂Ȃ��A�u���͂��Ă��邾���v�炵��" << endl
				<< "�Q�钼�O�������ɂ݂͉��ɂ����̂������̂��낤��" << endl
				<< "���̏��Ȃ����ŕ����邱�ƂȂ�Ă���̂��낤��" << endl;
			if (awareness <= 7) POTG++;
			POTD = 1;
			//awareness = 0;
			break;
		}
		cout << endl;
		POTD--;
		break;
	case SOLVING://����
		cout << "��������͏������Ƃɐ�������^�[��" << endl
			<< "������������I�ԁA�Ԉ�����I�����𐔉�I�Ԃƈ���̏��߂����蒼���ɂȂ�" << endl;
		Solve(POTG, POTD, awareness);
		break;
	case ENDING://�G���h
		MaxChoice = 1;
		POTD = 0;
		cout << "���āA�������悤��" << endl
			<< "1:�������m�F����" << endl;
		ChoiceNum(MaxChoice);
		cout << "������3��1���炵��" << endl
			 << endl
			 << "�Q�[���N���A" << endl
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
			cout << "�܂�������2��29���Ȃ̂��낤��" << endl
				 << "1:������" << endl 
				 << "2:�Ⴄ" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "�H���������Ă�����A�����p�i�������Ă�����" << endl
					 << "���Ԃ͊m���Ɍo�߂��Ă���" << endl
					 << "���������A�������Ԃ��J��Ԃ��Ȃǂ��蓾�Ȃ����Ƃ����炾" << endl
					 << endl;
			}
			else 
			{ 
				POTD--; 
				cout << "�Ⴄ" << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "���̊O�̌i�F�ɂ���" << endl
				 << "1:�f���ɂ��o�܂�����" << endl
				 << "2:�O�͓y�̂悤�ȕ��̂ōǂ���Ă���" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "�Z�Ȃ炻�ꂮ�炢���Ȃ��邾�낤" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "�Ⴄ" << endl;
			}
			system("pause");
			break;
		case 3:
			cout << "���ւ̃h�A�͌����������Ă��Ȃ��ɂ�������炸�A�J���Ȃ�" << endl
				 << "1:�{���Ƀh�A�͊J���Ȃ��̂��낤���A" << endl
				 << "2:���@�ł��g���Ă���̂��낤" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "�����ɂȂ��Ă��Ȃ��B�����A" << endl
					 << "�����������Ă��Ȃ��̂ɊJ���Ȃ��Ȃ�Ă��Ƃ͂��蓾�Ȃ��B" << endl
					 << "�e���O�o�����Ă���ȏ�A�h�A�͊J�����낤" << endl
					 << "�h�A���J���Ȃ��Ɗ��Ⴂ�A�����v�킳��Ă���̂ł͂Ȃ���" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "�Ⴄ" << endl;
			}
			system("pause");
			break;
		case 4:
			cout << "�e�͊O�o���Ă���A�A�������Ȃ��̂͂Ȃ���" << endl
				 << "1:�Y��Ă��邾���ŁA�e�͂������Ȃ��̂ł͂Ȃ���" << endl
				 << "2:�{���ɐe�ɘA�������̂��낤��" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "��������������Ă��Ȃ��B������͂�A" << endl
					 << "������J��Ԃ��Ă���Ǝv�킳��Ă����O�Ⴊ����" << endl
					 << "�A�������Ǝv�킳��Ă���̂ł͂Ȃ���" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "�Ⴄ" << endl;
			}
			system("pause");
			break;
		case 5:
			cout << "���̊ԐQ���ӂ�����悤�Ƃ����ۂ̒ɂ݂͉����낤��" << endl
				 << "1:�N���ɖ��炳����i�ł��������ꂽ�̂ł͂Ȃ���" << endl
				 << "2:�N������󂯂��ɂ݂ł͂Ȃ��̂ł͂Ȃ���" << endl;
			if (ChoiceNum(2) == 2)
			{
				cout << "�Q�钼�O��" << endl
					 << "�����狭���ɂ݂������Ƃ��Ă��A�C��ł����Ȃ�����A�ɂ݂ŐQ��Ȃ����낤" << endl
					 << "�����C�₷��قǂ̒ɂ݂ł���΁A�����o�Ă��Ă����������͂Ȃ�" << endl
					 << endl;
			}
			else
			{
				POTD--;
				cout << "�Ⴄ" << endl;
			}
			system("pause");
			break;
		case 7:
			cout << "���Ƃ����炱�̌J��Ԃ��̌����͒N�Ȃ̂��낤" << endl
				 << "1:���������Ď����Ȃ̂ł͂Ȃ����낤��" << endl
				 << "2:�e�͂��Ȃ��A�Z�͋��͎ҁA���̑�O�҂����݂���̂ł͂Ȃ���" << endl;
			if (ChoiceNum(2) == 1)
			{
				cout << "���������Ŏ�����������J��Ԃ��Ă���Ƃ����v�����݂����Ă��邾���Ȃ̂ł͂Ȃ���" << endl
					 << "��������΁A�G�ł͂��邪���_������" << endl
					 << "�������@�́c���o���邵���Ȃ����낤" << endl
					 << "���Ԃ�" << endl
					 << endl;
				POTG++;
			}
			else
			{
				POTD = 0;
				cout << "�Ⴄ" << endl;
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
			cout << "���̕ϓN���Ȃ��A�����̒�" << endl;
			break;
		case AWARENESS:
			cout << "�����̒��A��������������a����" << endl;
			break;
		case INVESTIGATE:
			cout << "�܂��J��Ԃ��A���������Ɍ������������낤" << endl;
			break;
		case SOLVING:
			cout << "���͖߂�Ȃ��A���낻��I��点�鎞�Ԃ�" << endl;
			break;
		case ENDING:
			cout << "���̕ϓN���Ȃ��A�����̒�" << endl;
			break;
	}
	cout << endl;
}

void ShowScreen(int POTD, int awareness)
{
	cout << "����" << POTD << endl
		<< "���o�x" << awareness << "/" << MaxAwareness << endl
		<< endl;

}

void HowToPlay()
{
	int choice = 0;
	bool endJudge = true;
	do
	{
		system("cls");
		cout << "�ǂ̐��������������ł����H" << endl
			<< "1:�Q�[���̓��e" << "2:��ʂ̐���"  << "3:�I��" << endl;
		do
		{
			cin >> choice;
		} while (choice < 1 || choice > 3);
		switch (choice)
		{
		case 1:
			cout << "�ڕW�͌J��Ԃ����X����̒E�o" << endl
				<< "1�����n�܂�����A�����̍s����I��������I�сA�������J��Ԃ��̌����������A�E�o��ڎw���܂�" << endl
				<< "�s�����Ɏ��Ԃ��i�݁A���̍s���Łu���o�x�v���オ���Ă����܂�" << endl
				<< "�ŏ��̖ړI�͎��o�x���グ�A�Q�[����i�s�����邱��" << endl
				<< "�I�ՁA���e�Ɋւ���y���Q�[��������܂��B" << endl
				<< "�������������̌��߂��������̂Ŋo���ē�����悤�ȃQ�[���ɂȂ��Ă��܂��B" << endl
				<< endl;

			system("pause");
			break;
		case 2:
			cout << "����" << 3 << "    <-����͈���ɍs���ł����" << endl
				<< "���o�x" << 1 << "/" << MaxAwareness << "    <-����̓Q�[���̐i�s�x" << endl
				<< "���o�x�ɂ���āA�Q�[���̐i�s�x������m�邱�Ƃ��ł��܂��B" << endl
				<< endl;

			system("pause");
			break;
		case 3:
			endJudge = false;
			break;
		}
	} while (endJudge);
}
