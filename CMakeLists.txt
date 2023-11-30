cmake_minimum_required(VERSION 3.26)
project(Hotel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64/lib/cmake")
include_directories(include)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Hotel main.cpp
        Entities/HotelRoom/Models/HotelRoomInterface.cpp
        Entities/HotelRoom/Models/HotelRoomInterface.h
        Entities/Equipment/Equipment.cpp
        Entities/Equipment/Equipment.h
        Entities/HotelRoom/Models/RegularHotelRoom.h
        Entities/HotelRoom/Models/BusinessClassHotelRoom.h
        Entities/HotelRoom/Models/LuxuryHotelRoom.h
        Entities/HotelRoom/HotelRoomBuilder.h
        Entities/Booking/Models/Client.cpp
        Entities/Booking/Models/Client.h
        Entities/Booking/Models/Booking.h
        DataBases/DataBaseAdapter.h
        DataBases/ClientDataBase.h
        DataBases/HotelRoomDataBase.h
        Entities/Booking/BookingBuilder.h
        QtWidgets/MainTabWindow/maintabwindow.cpp
        QtWidgets/MainTabWindow/maintabwindow.h
        QtWidgets/MainTabWindow/maintabwindow.ui
        QtWidgets/HotelRoomListWidget/hotelroomlistwidget.cpp
        QtWidgets/HotelRoomListWidget/hotelroomlistwidget.h
        QtWidgets/HotelRoomListWidget/hotelroomlistwidget.ui
        QtWidgets/ClientsListWidget/clientslistwidget.cpp
        QtWidgets/ClientsListWidget/clientslistwidget.h
        QtWidgets/ClientsListWidget/clientslistwidget.ui
        DataBases/DataBase.h
        include/json.hpp
        Entities/HotelRoom/HotelRoomJSONParser.h
        Entities/HotelRoom/HotelRoomJSONParser.cpp
        Entities/Booking/BookingJSONParser.cpp
        Entities/Booking/BookingJSONParser.h
        Entities/Booking/Models/Booking.cpp
        QtWidgets/AppendHotelRoomDialog/appendhotelroomdialog.cpp
        QtWidgets/AppendHotelRoomDialog/appendhotelroomdialog.h
        QtWidgets/AppendHotelRoomDialog/appendhotelroomdialog.ui
        DataBases/DataBase.cpp
)
target_include_directories(Hotel PUBLIC include)
target_link_libraries(Hotel
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
