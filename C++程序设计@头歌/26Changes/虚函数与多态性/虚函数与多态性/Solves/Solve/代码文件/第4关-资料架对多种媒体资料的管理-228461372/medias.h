#ifndef MEDIAS_H
#define MEDIAS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media {
protected:
    string name;
    string company;
public:
    Media(const string& n, const string& c) : name(n), company(c) {}
    virtual void showInfo() const = 0;
    virtual ~Media() {}
};

class AudioMedia : public Media {
private:
    string singer;
public:
    AudioMedia(const string& n, const string& c, const string& s)
        : Media(n, c), singer(s) {}

    void showInfo() const override {
        cout << "Audio Media:" << endl;
        cout << "Name: "    << name    << endl;
        cout << "Company: " << company << endl;
        cout << "Singer: "  << singer  << endl;
        cout << endl;
    }
};

class VideoMedia : public Media {
private:
    string actor;
public:
    VideoMedia(const string& n, const string& c, const string& a)
        : Media(n, c), actor(a) {}

    void showInfo() const override {
        cout << "Video Media:" << endl;
        cout << "Name: "    << name    << endl;
        cout << "Company: " << company << endl;
        cout << "Actor: "   << actor   << endl;
        cout << endl;
    }
};

class Software : public Media {
private:
    string version;
public:
    Software(const string& n, const string& c, const string& v)
        : Media(n, c), version(v) {}

    void showInfo() const override {
        cout << "Software:" << endl;
        cout << "Name: "    << name    << endl;
        cout << "Company: " << company << endl;
        cout << "Version: " << version << endl;
        cout << endl;
    }
};

class Shelf {
private:
    vector<Media*> items;
public:
    void add(Media* m) { items.push_back(m); }

    void printMediaInfo() const {
        for (Media* m : items) {
            m->showInfo();
        }
    }
    ~Shelf() {
        for (Media* m : items) delete m;
    }
};

#endif