var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('my_books');
});

router.post('/', function (req, res, next) {

	var s_id = req.body['s_id'];

    mysqlDB.query('select * from borrower where s_id = ?',[s_id], function (err, rows, fields){
		if (!err) {                         //오류가 없으면 웹 페이지에 값 출력
            if (rows[0]!=undefined) {       //row가 존재하면 회원정보 출력
                //회원정보 각 변수에 저장

				var i = 0;
				while (rows[i] != undefined)
					i++;
				var result = new Array(i);
				var j = 0;
				var ret;
				while (j != i){
					result[j] = 'no : ' + JSON.stringify(rows[j]['no']) +
					's_name : ' + JSON.stringify(rows[j]['s_name'])+
					'b_name : ' +JSON.stringify(rows[j]['b_name']) +
					'loan_date : ' + JSON.stringify(rows[j]['loan_date']) +
					'return_date : ' + JSON.stringify(rows[j]['return_date']) +'<br>';
					j++;
				}
				j = 0;
				/*while(j != i - 1)
					ret = arr.concat(result[j]);*/
				res.send(JSON.stringify(result));
            } else {                    
                res.send('No books borrowed from the library');
            }

        } else {                        //오류가 있으면 오류코드 출력
            res.send('error : ' + err);
        }
    });
});


module.exports = router;

