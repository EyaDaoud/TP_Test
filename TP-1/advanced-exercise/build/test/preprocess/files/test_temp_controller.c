#include "build/test/mocks/mock_temp_sensor.h"
#include "src/temp_controller.h"
#include "/home/kamel/.rbenv/versions/2.7.8/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {

    mock_temp_sensor_Init();

}



void tearDown(void) {

    mock_temp_sensor_Verify();

    mock_temp_sensor_Destroy();

}



void test_check_temperature_should_return_1_when_too_hot(void) {

    read_temperature_sensor_CMockExpectAndReturn(15, 31);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_minus_1_when_too_cold(void) {

    read_temperature_sensor_CMockExpectAndReturn(20, 14);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}



void test_check_temperature_should_return_0_when_normal(void) {

    read_temperature_sensor_CMockExpectAndReturn(25, 20);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

}







void test_check_temperature_should_handle_exact_limits(void) {

    read_temperature_sensor_CMockExpectAndReturn(32, 15);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(35, 30);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);





}



void test_check_temperature_should_handle_sensor_failure(void) {

    read_temperature_sensor_CMockExpectAndReturn(42, -50);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);



    read_temperature_sensor_CMockExpectAndReturn(45, 130);

    UnityAssertEqualNumber((UNITY_INT)((-2)), (UNITY_INT)((check_temperature())), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}
