var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('borrow');
});

router.post('/', function (req, res, next) {

	var s_id = req.body['s_id'];
	var s_name = req.body['s_name'];
	var phone = req.body['phone'];
	var b_name = req.body['b_name'];
	var auto_inc = '';
	let today = new Date();
	var now = String(today.getFullYear()) + '-' + String(today.getMonth() + 1) + '-' + String(today.getDate());
	var nowArray = now.split("-");
	for(var i = 0; i < 3; i ++)
		nowArray[i] = Number(nowArray[i]);
	nowArray[2] += 7;
	if (nowArray[2] > 31 && (nowArray[1] == 1 || nowArray[1] == 3 || 
		nowArray[1] == 5 || nowArray[1] == 7 || nowArray[1] == 8 || 
		nowArray[1] == 10 || nowArray[1] == 12)){
		nowArray[2] = nowArray[2] - 31;
		if (nowArray[1] == 12){
			nowArray[0]++;
			nowArray[1] == 1;
		}
		else
			nowArray[1]++;
	}
	else if (nowArray[2] > 28 && nowArray[1] == 2){
		nowArray[1]++;
		nowArray[2] = nowArray[2] - 28;
	}
	else if (nowArray[2] > 30 && (nowArray[1] == 4 || nowArray[1] == 6 ||
		nowArray[1] == 9 || nowArray[1] == 1)){
		nowArray[1]++;
		nowArray[2] = nowArray[2] - 30;
	}
	var return_dt = nowArray[0] + '-' + nowArray[1] + '-' + nowArray[2];

	mysqlDB.query('select count(*) from borrower where b_name = ?', [b_name], function (err, rows, fields) {
		if (!err){
			if (rows[0]['count(*)'] == 0){
				mysqlDB.query('insert into borrower values(?,?,?,?,?,?,?)', [auto_inc,s_id, s_name, phone, b_name,now, return_dt], function (err, rows, fields) {
				if (!err){
					res.send('borrowed successfully');
				}
				else{
					res.send('please check the book');
				}
				});
			}
			else {
				res.send('someone already borrowed the book');
			}
		}
		else{
			res.send('err : ' + err);
		}
	});
});


module.exports = router;

