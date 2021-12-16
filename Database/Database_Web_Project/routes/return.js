var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('return');
});

router.post('/', function (req, res, next) {

	var s_id = req.body['s_id'];
	var b_name = req.body['b_name'];
	
	mysqlDB.query('select count(*) from borrower where b_name = ? && s_id = ?', [b_name, s_id], function (err, rows, fields) {
		if (!err){
			if (rows[0]['count(*)'] == 1){
				mysqlDB.query('delete from borrower where b_name = ? && s_id = ?', [b_name, s_id], function (err, rows, fields) {
					if (!err){
							res.send('successfully returned the book ' + b_name);
					}
					else{
						res.send('err : ' + err);
					}
				});
			}
			else{
				res.send('there is error matching book name and id');
			}
		}
		else {
			res.send('err : ' + err);
		}
	});
});


module.exports = router;

