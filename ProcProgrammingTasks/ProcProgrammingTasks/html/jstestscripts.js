let a = 1;
let a_min = 0;
let a_max = 19;

let img1 = "<img src=\"1.png\"></img>";
let img2 = "<img src=\"2.png\"></img>";
let img3 = "<img src=\"3.png\"></img>";

function min(a, b)
{
    if (a < b) return a;
    else return b;
}

function update()
{
    cur = document.getElementById("current_a");
    let temp = "";
    for (let i = 0; i < min(a, a_max); i++)
    {
        if (i == a-1)
        {
            if (a == a_max+1)
            {
                temp += img1;
            }
            else
                temp += img2;
        }
        else
        {
            temp += img1;
        }
    }
    for (let i = a; i < a_max; i++)
    {
        temp += img3;
    }
    cur.innerHTML = temp;
}

function decrease()
{
    if (a - 1 >= a_min)
    {
        a--;
    }
    update();
}

function increase()
{
    if (a + 1 <= a_max+1)
    {
        a++;
    }
    update();
}