var MongoClient = require('mongodb').MongoClient;

exports.list = function(nedb){
	return function(req, res){
		nedb.find({}, function (err, docs) {
			if (err || docs.length == 0) {
				console.log("Nedb has no data! So now we start to cache it!"); //test1
				MongoClient.connect('mongodb://127.0.0.1:27017/sfo_TW', function(err, db) {
					if (err)
						throw err;

					var collection = db.collection('T1S.TW.future.TX_201309');
					collection.find().toArray(function(err, results) {
						nedb.insert(results, function (err, newDoc) {
							if (err)
								throw err;
							
							console.log("Nedb succeeded to cache data! Now show it!"); //test1
							res.json(newDoc);
							//res.json(results);
							db.close();
						});
					});
				});
			} else {
				console.log("Nedb has data! Directly use it!"); //test1
				res.json(docs);
			}
		});
	};
};