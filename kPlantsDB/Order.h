namespace kPlantsDB
{
  class Order
  {
  public:
    Plantae kingdom() const;
  private:
    struct Private;
    Private* const d;
  };
}
