if(EXISTS "C:/Users/Gabriel/Desktop/Repositories/almoxarifado/build/almoxarifado.core.tests/almoxarifado.core.tests[1]_tests.cmake")
  include("C:/Users/Gabriel/Desktop/Repositories/almoxarifado/build/almoxarifado.core.tests/almoxarifado.core.tests[1]_tests.cmake")
else()
  add_test(almoxarifado.core.tests_NOT_BUILT almoxarifado.core.tests_NOT_BUILT)
endif()
