#![allow(non_snake_case)]

fn get_input() -> Vec<i32> {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Failed to read input");
    let v = input.split_whitespace()
                        .map(|x| x.parse::<i32>())
                        .collect::<Result<Vec<i32>, _>>()
                        .unwrap();
    v
}
fn main() {
    let v = get_input();
    let N = v[0];
    let Q = v[1];
    let mut root = get_input();
    root.sort();

    for _i in 0..Q  {
        let x = get_input().get(0).unwrap().clone();
        let mut right = N - 1;
        let mut left = 0i32;
        let mut result = right / 2;

        while right >= left && root.get(result as usize).unwrap() != &x {
            let middle = (right + left) / 2;
            let store = root.get(middle as usize).unwrap();
            if store >= &x {
                result = middle;
            }
            if store < &x {
                left = middle + 1 as i32;
            }else if store > &x {
                right = middle - 1 as i32;
            }
        }

        let upper_bound_root = root.get(result as usize).unwrap();

        if upper_bound_root != &x {
            if upper_bound_root < &x {
                println!("POSITIVE");
            }else {
                let length = N - result;
                if length % 2 != 0 {
                    println!("NEGATIVE");
                }else{
                    println!("POSITIVE");
                }
            }
        }else{
            println!("0");
        }
    }
} 