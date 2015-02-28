set(KPLANTSDB_SRCS DatabaseConnection.cpp Order.cpp Plantae.cpp QueryResult.cpp)
add_library(kPlantsDB ${KPLANTSDB_SRCS})
target_link_libraries(kPlantsDB Qt5::Core Qt5::Network)