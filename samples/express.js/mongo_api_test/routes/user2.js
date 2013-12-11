var MongoClient = require('mongodb').MongoClient;

var trade_time_begin = "08:45:00";
var trade_time_end = "13:45:00";

exports.list = function(cache) {
	return function(req, res) {
		if (typeof cache["T1S.TW.future.TX_201309"] == "undefined") {
			console.log("No data in cache! So now we start to cache it!"); //test1
			MongoClient.connect('mongodb://127.0.0.1:27017/sfo_TW', function(err, db) {
				if (err)
					throw err;

				var collection = db.collection('T1S.TW.future.TX_201309');
				collection.find().toArray(function(err, results) {
					//Put dummy price data at here!!
					console.log("Start to put dummy price data into results array!"); //test1
					var price_data = [];
					for (var i = 0; i < results.length; i++) {
						price_data.push(results[i]);
					}
					//Then cache it!!
					cache["T1S.TW.future.TX_201309"] = price_data;
					console.log("Finish caching! Now show it! price_data len: " + price_data.length); //test1
					res.json(price_data);
					db.close();
				});
			});
		} else {
			console.log("Data in cache! Directly use it!"); //test1
			res.json(cache["T1S.TW.future.TX_201309"]);
		}
	};
};