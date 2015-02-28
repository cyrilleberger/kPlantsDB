#include <QSharedDataPointer>
#include <QList>

namespace kPlantsDB
{
  class DatabaseConnection;
  class Order;
  class Plantae
  {
  public:
    Plantae(DatabaseConnection* _connection);
    Plantae(const Plantae& _other);
    Plantae operator=(const Plantae& _other);
    ~Plantae();
    QList<Order> orders() const;
  private:
    struct Private;
    QSharedDataPointer<Private> d;
  };
}