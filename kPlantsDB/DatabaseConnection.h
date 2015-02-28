#include <QString>

namespace kPlantsDB
{
  class QueryResult;
  class DatabaseConnection
  {
  public:
    DatabaseConnection();
    ~DatabaseConnection();
    QueryResult execute(const QString& _str);
  private:
    struct Private;
    Private* const d;
  };
}
