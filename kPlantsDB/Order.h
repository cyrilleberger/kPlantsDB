#include <QSharedDataPointer>

namespace kPlantsDB
{
  class DatabaseConnection;
  class Order
  {
  public:
    Order(const QString& _entityId, DatabaseConnection* _connection);
    Order(const Order& _other);
    Order& operator=(const Order& _other);
    ~Order();
    QString name() const;
  private:
    struct Private;
    QSharedDataPointer<Private> d;
  };
}
