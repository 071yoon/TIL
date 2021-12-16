var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('all_books');
});

router.post('/', function (req, res, next) {

    mysqlDB.query('select * from book', function (err, rows, fields){
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
					result[j] = 'b_code : ' + JSON.stringify(rows[j]['b_code']) +
					'b_name : ' + JSON.stringify(rows[j]['b_name'])+
					'author : ' +JSON.stringify(rows[j]['author']) +
					'price : ' + JSON.stringify(rows[j]['price']) +
					'publish : ' + JSON.stringify(rows[j]['publish']) +'<br>';
					j++;
				}
				j = 0;
				/*while(j != i - 1)
					ret = arr.concat(result[j]);*/
				res.send(JSON.stringify(result));
            } else {                    
                res.send('회원 정보가 없습니다');
            }

        } else {                        //오류가 있으면 오류코드 출력
            res.send('error : ' + err);
        }
    });
});


module.exports = router;

