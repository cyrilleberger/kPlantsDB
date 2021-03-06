#include "DatabaseConnection.h"
#include "QueryResult.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

using namespace kPlantsDB;

struct DatabaseConnection::Private
{
  QNetworkAccessManager manager;
};

DatabaseConnection::DatabaseConnection() : d(new Private)
{

}

DatabaseConnection::~DatabaseConnection()
{
  delete d;
}

QueryResult DatabaseConnection::execute(const QString& _str)
{
//   QNetworkRequest request(QUrl("http://dbpedia.org/sparql?default-graph-uri=http%3A%2F%2Fdbpedia.org&query=select+distinct+%3Fy+where+%7B%0D%0A%3Fx+%3Chttp%3A%2F%2Fdbpedia.org%2Fproperty%2Fregnum%3E+%22Plantae%22%40en+.%0D%0A%3Fx+dbpedia-owl%3Aorder+%3Fy%0D%0A%7D+LIMIT+100%0D%0A&format=text%2Fhtml&timeout=30000&debug=on"));
  QUrlQuery query;
  query.addQueryItem("default-graph-uri", "http://dbpedia.org");
  query.addQueryItem("query", _str);
  query.addQueryItem("format", "application/sparql-results%2Bjson");

  QUrl url("http://dbpedia.org/sparql");
  url.setQuery(query);
  
  QNetworkRequest request(url);
  
  QNetworkReply*  reply = d->manager.get(request);
  
  QEventLoop loop;
  QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
  if(not reply->isFinished()) loop.exec();
  
  reply->deleteLater();

  QByteArray arr = reply->readAll();
  QJsonDocument doc = QJsonDocument::fromJson(arr);
  QJsonArray array = doc.object()["results"].toObject()["bindings"].toArray();
  QList<QueryResult::Line> lines;
  
  for(int i = 0; i < array.count(); ++i)
  {
    QJsonObject obj = array.at(i).toObject();
    QueryResult::Line line;
    for(QString key : obj.keys())
    {
      QJsonValue value = obj[key];
      line[key] = value.toVariant();
    }
    lines.append(line);
  }
  return QueryResult(lines);
}




