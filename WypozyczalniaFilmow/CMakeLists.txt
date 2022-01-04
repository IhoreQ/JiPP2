cmake_minimum_required(VERSION 3.20)
project(WypozyczalniaFilmow)

set(CMAKE_CXX_STANDARD 17)

add_executable(WypozyczalniaFilmow src/main.cpp include/User.h include/Recording.h include/Film.h include/Series.h include/Review.h src/Film.cpp src/Recording.cpp src/Review.cpp src/User.cpp src/Series.cpp include/Rental.h src/Rental.cpp include/helpfulFunctions.h src/helpfulFunctions.cpp)
