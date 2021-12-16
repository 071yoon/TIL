var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('extend');
});

router.post('/', function (req, res, next) {

	var s_id = req.body['s_id'];
	var b_name = req.body['b_name'];


	mysqlDB.query('select return_date from borrower where s_id = ? and b_name = ?', [s_id, b_name], function (err, rows, fields) {
		if (!err){
			if (rows[0] != undefined){

				var now = String(rows[0]['return_date'].getFullYear()) + '-' + String(rows[0]['return_date'].getMonth() + 1) + '-' + String(rows[0]['return_date'].getDate());
				var nowArray = now.split('-');
			
				for(var i = 0; i < 3; i ++)
					nowArray[i] = Number(nowArray[i]);
				nowArray[2] += 7;
				if (nowArray[2] > 31 && (nowArray[1] == 1 || nowArray[1] == 3 || 
					nowArray[1] == 5 || nowArray[1] == 7 || nowArray[1] == 8 || 
					nowArray[1] == 10 || nowArray[1] == 12)){
					nowArray[2] = nowArray[2] - 31;
					if (nowArray[1] == 12){
						nowArray[0]++;
						nowArray[1] = 1;
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




				mysqlDB.query('update borrower set return_date = ? where s_id = ? and b_name = ?', [return_dt, s_id, b_name], function (err, rows, fields) {
					if (!err){
						res.send('extended succesfully');
					}
					else{
						res.send('err : ' + err);
					}
				});

			}
			else {
				res.send('not here');
			}
		}
		else{
			res.send('err : ' + err);
		}
	});
});


module.exports = router;

