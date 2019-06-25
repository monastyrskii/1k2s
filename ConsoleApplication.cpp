#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;


class HumanBeing {
public:
	int health, x, y;
	string name;
	HumanBeing() {
	}
};

class YandexFood : public HumanBeing {
	friend class gopnik;
	friend int checkfoodYa(YandexFood &kur);
private:
	class heart {
	public:
		int bpm = 80;
		heart() {
			bpm += 50;
			cout << " и его сердце сейчас бьется с частотой " << bpm << " ударов в минуту.\n";
		}
	};
	int hmfood = 20; // how much food
public:
	YandexFood(string name, int x, int y) : HumanBeing() {
		health = 100;
		this->name = name;
		this->x = x;
		this->y = y;
		hmfood = rand();
		cout << "Привет, меня зовут " << name << " и я доставляю еду.\n";
	}
	void move() {
		int randx(100), randy(100);
		while (randx > 15 || randy < -15) {
			randx = int(random());
		}
		while (randy > 15 || randy < -15) {
			randy = int(random());
		}
		x = x + randx;
		y = y + randy;
		cout << "Курьер по имени " << name << " переместился в точку (" << x << ";" << y << ")\n";
	}
	void afraid() {
		cout << "Курьер по имени " << name << " испугался ";
		heart();
	}
};

int checkfoodYa(YandexFood &kur) {
	kur.hmfood = kur.hmfood - 5;
	return kur.hmfood;
}

class DeliveryClub : public YandexFood {
	friend class gopnik;
	friend int checkfoodD(DeliveryClub &kur);
private:
	class heart {
	public:
		int bpm = 80;
		heart() {
			bpm += 50;
			cout << " и его сердще сейчас бьется с частотой " << bpm << "ударов в минуту.\n";
		}
	};
	int hmfood = 20;
public:
	DeliveryClub(string name, int x, int y) : YandexFood(name, x, y) {
	}
};

int checkfoodD(DeliveryClub &kur) {
	kur.hmfood = kur.hmfood - 5;
	return kur.hmfood;
}


class gopnik : public HumanBeing {
public:
	int xr, yr, square; // x range, y range - в этих пределах гопник смотрит, есть ли кто-либо
	gopnik(string name, int xr, int yr, int square) : HumanBeing() {
		cout << "Дарова, меня зовут " << name << " и я держу район от " << xr << " до " << xr + int(sqrt(square)) << " по x и от " << yr << " до " << yr + int(sqrt(square)) << " по у. Только попробуй сюда зайти!! \n";
		this->xr = xr;
		this->yr = yr;
		this->square = square;
	}
	void checkYa(YandexFood kur) {
		if (kur.x > xr && kur.x < xr + int(sqrt(square)) && kur.y > yr && kur.y < yr + int(sqrt(square))) {
			kur.afraid();
			kur.health = 0;
			int kurfood = checkfoodYa(kur);
			cout << "Гопник забрал у курьера 5 кг еды. Здоровье курьера по имени " << kur.name << " снизилось до нуля. У него осталось " << kurfood << " килограммов еды\n";
		}
	}
	void checkDev(DeliveryClub kur) {
		if (kur.x > xr && kur.x < xr + int(sqrt(square)) && kur.y > yr && kur.y < yr + int(sqrt(square))) {
			kur.afraid();
			kur.health = 0;
			int kurfood = checkfoodD(kur);
			cout << "Гопник забрал у курьера 5 кг еды. Здоровье курьера по имени " << kur.name << " снизилось до нуля. У него осталось " << kurfood << " килограммов еды\n";
		}
	}
};

bool operator > (YandexFood kur1, DeliveryClub kur2) {
	if (kur1.health > kur2.health) {
		return true;
	}
	else return false;
}
bool operator < (YandexFood kur1, DeliveryClub kur2) {
	if (kur1.health < kur2.health) {
		return true;
	}
	else return false;
}


int main() {
	setlocale(LC_ALL, "Russian");
	YandexFood kur1("Катя", 0, 100), kur2("Евгений", 15, 62), kur3("Борис", 100, 100);
	DeliveryClub dkur1("Юля", 50, 75), dkur2("Аня", 63, 0), dkur3("Виктор", 75, 53);
	gopnik sanya("Никитос", 20, 20, 1000), igor("Игорь", 75, 75, 750);
	int i(0);
	for (i = 1; i <= 10; i++) {
		kur1.move(); kur2.move(); kur3.move(); dkur1.move(); dkur2.move(); dkur3.move();
		cout << endl << endl;
		sanya.checkYa(kur1); sanya.checkYa(kur2); sanya.checkYa(kur3); sanya.checkDev(dkur1); sanya.checkDev(dkur2); sanya.checkDev(dkur3);
		igor.checkYa(kur1); igor.checkYa(kur2); igor.checkYa(kur3); igor.checkDev(dkur1); igor.checkDev(dkur2); igor.checkDev(dkur3);
		cout << endl << endl;
	}


}

