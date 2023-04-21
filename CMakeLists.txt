cmake_minimum_required(VERSION 3.25)
project(FortMyersFerries)

set(CMAKE_CXX_STANDARD 17)

add_executable(FortMyersFerries main.cpp Account.cpp Account.h AdminAccount.cpp AdminAccount.h CurrentFerriesDisplay.cpp CurrentFerriesDisplay.h DatabaseConnection.cpp DatabaseConnection.h DisplayElement.h Ferry.cpp Ferry.h FerryData.cpp FerryData.h GuestAccount.cpp GuestAccount.h Observer.h Reservation.cpp Reservation.h sqlite3.c sqlite3.h Subject.h UserAccount.cpp UserAccount.h)

find_package(OpenSSL REQUIRED)
target_link_libraries(FortMyersFerries OpenSSL::SSL)






