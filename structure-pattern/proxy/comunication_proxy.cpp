#include "string"
#include "iostream"

using namespace std;

struct Pingable {
    virtual string ping(const string& msg) = 0;
};

struct Pong : Pingable {
    string ping(const string& msg) {
        return msg + " pong";
    }
};

void tryit(Pingable& pp) {
    cout << pp.ping("ping") <<endl;
}


/**
 * code sẽ được đẩy lên 1 máy khác
 * */

struct RemotePong : Pingable{
    string ping(const string& msg) override {
        string result;
        //code fake
        /**
         * http_client client("http://localhost:8080");
         * uri_builder builder("/api/pingpong/");
         * builder.append(msg);
         * auto task = client.request(
         *  methods::GET, builder.to_string()
         * ).then([=](http_response r) {
         *  return r.extract_string();
         * });
         * task.wait();
         * return task.get();
        */

        return result;
    }
};


int main(){
    Pong pp;
    for(int i = 0; i < 3; i++){
        tryit(pp);
    }

    RemotePong rpp;
    for(int i = 0; i < 3; i++){
        tryit(rpp);
    }

    return 0;
}