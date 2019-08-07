
function pushBtn(obj){
	var result = document.getElementById("result");
	var pushed = obj.innerHTML;
	if (pushed == "="){
		// calculate
		result.innerHTML = eval(result.innerHTML);
	} else if (pushed == "C"){
		// clear
		result.innerHTML = "0";
	} else {
		if (result.innerHTML == "0"){
			result.innerHTML = pushed;
		} else {
			result.innerHTML = result.innerHTML + pushed;
		}
	}
};