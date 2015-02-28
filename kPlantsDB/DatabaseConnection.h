#include <QString>

namespace kPlantsDB
{
  class DatabaseConnection
  {
  public:
    DatabaseConnection();
    ~DatabaseConnection();
    void execute(const QString& _str);
  private:
    struct Private;
    Private* const d;
  };
}
