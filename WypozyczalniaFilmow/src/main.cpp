#include <iostream>
#include <limits>
#include <fstream>
#include "../include/Film.h"
#include "../include/Recording.h"
#include "../include/Review.h"
#include "../include/Series.h"
#include "../include/User.h"
#include "../include/Rental.h"
#include "../include/helpfulFunctions.h"

using namespace std;

int main(int argc, char* argv[]) {

    Rental VOD;
    VOD.run(argc, argv);
    return 0;
}