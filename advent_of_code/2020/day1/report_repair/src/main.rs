use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader, Error, ErrorKind};
use std::vec::Vec;

const SUMTO: i64 = 2020;

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    let filename = &args[1];
    let file = File::open(filename)?;
    let br = BufReader::new(file);
    let mut v: Vec<i64> = Vec::with_capacity(2020);
    for line in br.lines() {
        let line = line?;
        let n = line
            .parse()
            .map_err(|e| Error::new(ErrorKind::InvalidData, e))?;
        v.push(n);
    }
    v.sort_unstable();
    println!("two sum multi = {}", find_two_sum(&mut v));
    println!("three sum multi = {}", find_three_sum(&mut v));

    Ok(())
}

fn find_two_sum(v: &mut Vec<i64>) -> i64 {
    let mut rst = 0;
    for (i, val) in v.iter().enumerate() {
        let idx = v.binary_search(&(SUMTO - val)).unwrap_or(usize::MAX);
        if idx != usize::MAX && i != idx {
            println!("Found:{},{} sum = {}", i, idx, v[i] + v[idx]);
            println!("Found:{}*{} = {}", v[i], v[idx], v[i] * v[idx]);
            rst = v[i] * v[idx];
            break;
        }
    }
    rst
}

fn find_three_sum(v: &mut Vec<i64>) -> i64 {
    let mut rst = 0;
    for (i, val) in v.iter().enumerate() {
        for j in (i + 1)..v.len() {
            let idx = v.binary_search(&(SUMTO - val - v[j])).unwrap_or(usize::MAX);
            if idx != usize::MAX && i != idx {
                println!("Found:{},{},{} sum = {}", i, j, idx, v[i] + v[j] + v[idx]);
                println!(
                    "Found:{}*{}*{} = {}",
                    v[i],
                    v[j],
                    v[idx],
                    v[i] * v[j] * v[idx]
                );
                rst = v[i] * v[j] * v[idx];
                break;
            }
        }
        if rst > 0 {
            break;
        }
    }
    rst
}
