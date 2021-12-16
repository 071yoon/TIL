var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('donate');
});

router.post('/', function (req, res, next) {

	var b_code = req.body['b_code'];
	var b_name = req.body['b_name'];
	var author = req.body['author'];
	var price = req.body['price'];
	var publish = req.body['publish'];

	if (b_code.length == 4){
		mysqlDB.query('insert into book values(?,?,?,?,?)', [b_code, b_name, author, price, publish], function (err, rows, fields) {
			if (!err) {                 //오류가 없을 때 아래의 코드 실행
				res.send('successfully donated to the library');
			} else {                    //오류가 있으면 오류코드 출력
				res.send('err : ' + err);
			}
		});
	}
	else{
		res.send('b_code must be size of 4');
	}
});


module.exports = router;

