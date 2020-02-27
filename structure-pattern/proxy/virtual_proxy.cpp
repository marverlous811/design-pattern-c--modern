#include "string"
#include "iostream"

using namespace std;

struct Image {
    virtual void draw() = 0;
};

struct Bitmap : Image {
    string filename;
    Bitmap(const string& filename) : filename{filename} {
        cout << "Loading image from " << filename << endl;
    }

    void draw() override {
        cout << "Drawing image " << filename << endl;
    }
};

struct LazyBitmap : Image {
private:
    string filename;
    Bitmap *bmp{nullptr};
public:
    LazyBitmap(const string& filename) : filename{filename} {

    }
    ~LazyBitmap() { delete bmp; }
    void draw() override {
        if(!bmp) 
            bmp = new Bitmap(filename);
        bmp->draw();
    }
};

void draw_image(Image& img){
    cout<<"About to draw the image"<<endl;
    img.draw();
    cout<<"Done drawing the image"<<endl;
}

int main(){
    LazyBitmap img{"pokemon.png"};
    draw_image(img);

    return 0;
}