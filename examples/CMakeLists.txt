add_executable(query_example QueryExample.cpp)
target_link_libraries(query_example kPlantsDB)

add_executable(all_orders AllOrders.cpp)
target_link_libraries(all_orders kPlantsDB)
