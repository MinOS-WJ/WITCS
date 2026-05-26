#include <iostream>
using namespace std;

/********* Begin *********/
class Car
{
private:
    bool door;
    bool light;
    int speed;
public:
    Car() : door(false), light(false), speed(0) {}
    void openDoor()   { door = true;  }   // 修正
    void closeDoor()  { door = false; }
    void openLight()  { light = true; }
    void closeLight() { light = false;}
    void speedUp()    { speed += 10;  }
    void speedDown() { 
        if (speed >= 10) speed -= 10; 
    }
    void print() const {
        cout << "车门 " << (door  ? "ON" : "OFF") << endl;  // 加空格
        cout << "车灯 " << (light ? "ON" : "OFF") << endl;
        cout << "速度 " << speed << endl;
    }
};
/********* End *********/

int main()
{
    /********* Begin *********/
    char cmds[25];
    cin >> cmds;
    Car car;
    for (int i = 0; cmds[i] != '\0'; i++) {
        switch (cmds[i]) {
            case '1': car.openDoor();   break;
            case '2': car.closeDoor();  break;
            case '3': car.openLight();  break;
            case '4': car.closeLight(); break;
            case '5': car.speedUp();    break;
            case '6': car.speedDown();  break;
        }
    }
    car.print();
    return 0;
    /********* End *********/
}