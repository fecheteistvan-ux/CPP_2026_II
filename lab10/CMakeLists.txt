project(lab10)
add_executable(lab10 main_10.cpp
        Student.cpp
        Student.h
        GraduationDao.cpp
        GraduationDao.h
        StudentService.cpp
        StudentService.h
        StudentServiceImpl.cpp
        StudentServiceImpl.h
        names.txt
        math.txt
        romanian.txt
        hungarian.txt)
file(COPY names.txt hungarian.txt romanian.txt math.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})