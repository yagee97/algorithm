
public class 카카오2020_문자열압축 {
	
	public static void main(String[] args) {
		String str = "ababcdcdababcdcd";
		int answer = solution(str);
		System.out.println(answer);
	}
	
	static public int solution(String s) {
		int min = s.length();
		// unit 단위만큼 검사 1~문자열 절반
		for (int unit = 1; unit <= s.length()/2; unit++) {
			int start = 0;
			int end = start + unit;
			int compress = 0;
			int cnt = 1;
			
			// unit 만큼 자른 첫 문자열
			String cut = s.substring(start, end);
			String next;
			
			// unit만큼 건너뛴 인덱스
			start += unit;
			end += unit;
			
			// 문자열 끝까지 검사
			while(end <= s.length()) {
				next = s.substring(start, end);
				
				// next가 현재 반복 문자열과 달라질때 압축길이를 com에 더한다.
				if(!cut.equals(next)) {
					
					//반복이 1이 넘으면, 압축수를 길이에 고려
					if (cnt>1) {
						compress += (int)(Math.log10(cnt)+1);
						//compress += cnt;
					}
					compress += cut.length();
					
					cnt = 0;
					cut = next;
				}
				
				// 문자열이 반복되면 반복 카운트 증가, 그리고 비교 단어 옆으로 옮기기
				cnt++;
				start += unit;
				end += unit;
			}
			
			// while문 빠져나가면서 반복이 없는 애들 압축 길이 추가
			end -= unit;
			compress += s.substring(end).length();
			
			if (cnt > 1) {
				compress += (int)(Math.log10(cnt)+1);
			}
			compress += cut.length();
			
			if(min > compress)
				min = compress;
		}
		
		return min;
	}
	
}
