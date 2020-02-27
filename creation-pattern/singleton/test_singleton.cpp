#include "singleton.h"
#include <gtest/gtest.h>

TEST(RecordFinderTests, SingletonTotalPopulationTest){
    SingletonRecordFinder rf;
    vector<string> names{"Seoul", "Mexico City"};
    int tp = rf.total_population(names);
    EXPECT_EQ(17500000 + 17400000, tp);
};

TEST(RecordFinderTests, DependentTotalPopulationTest){
    DummyDatabase db;
    ConfiguratableRecordFinder rf{db};
    EXPECT_EQ(4, rf.total_population(vector<string>{"alpha","gamma"}));
};


int main(int ac, char* av[]){
    SingletonDatabase::get();
    // string city = "Tokyo";
    // cout<<"city "<<city<<" has population "<<SingletonDatabase::get().get_population(city)<<endl;
    
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}