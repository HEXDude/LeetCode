package DATA_STRUCTURE;

/**
 * @author HEXDude
 * @data 2021/10/16
 * @desciption
 * @see <a href =
 *      "https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/">买卖股票的最佳时间</a>
 */
public class BEST_TIME_TO_BUY_AND_SELL_STOCK {

    public static void main(String[] args) {
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        new Solution1().maxProfit(prices);
    }

}

class Solutions {

    /**
     * 从后往前进行运算
     * 如果没有比0大的说明无钱可赚
     * 比0大的会进行比较，大值永远
     * 赋值给maxProfit
     * 有个疑问：是否可以当天买当天卖
     * 暴力解法在大批量时会运算超时
     */
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for (int i = prices.length - 1; i >=0; i--) {
            for (int j = i; j>= 0; j--) {
                int assumeProfit = prices[i] - prices[j];
                if (assumeProfit > maxProfit) {
                    maxProfit = assumeProfit;
                }
            }
        }
        return maxProfit;
    }
}

class Solution1 {

    /**
     * 
     */
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minCost = prices[0];
        for (int i = 1; i < prices.length; i++) {
            //获取购买成本的最小值
           minCost = Math.min(minCost, prices[i]);
           maxProfit = Math.max(maxProfit, prices[i] - minCost);
        }
        return maxProfit;
    }
}

