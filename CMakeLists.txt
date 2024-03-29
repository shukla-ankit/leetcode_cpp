cmake_minimum_required(VERSION 3.15)
project(leetcode_cpp)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(0001_TwoSum src/0001_TwoSum.cpp)
add_executable(0002_AddTwoNumbers src/0002_AddTwoNumbers.cpp)
add_executable(0003_LongestSubstringWithoutRepeatingCharacters src/0003_LongestSubstringWithoutRepeatingCharacters.cpp)
add_executable(0004_MedianofTwoSortedArrays src/0004_MedianofTwoSortedArrays.cpp)
add_executable(0005_LongestPalindromicSubstring src/0005_LongestPalindromicSubstring.cpp)
add_executable(0006_ZigZagConversion src/0006_ZigZagConversion.cpp)
add_executable(0007_ReverseInteger src/0007_ReverseInteger.cpp)
add_executable(0008_StringtoInteger src/0008_StringtoInteger.cpp)
add_executable(0009_PalindromeNumber src/0009_PalindromeNumber.cpp)
add_executable(_0010_RegularExpressionMatching src/_0010_RegularExpressionMatching.cpp)
add_executable(0010_RegularExpressionMatching src/0010_RegularExpressionMatching.cpp)
add_executable(0011_ContainerWithMostWater src/0011_ContainerWithMostWater.cpp)
add_executable(0012_IntegertoRoman src/0012_IntegertoRoman.cpp)
add_executable(0013_RomantoInteger src/0013_RomantoInteger.cpp)
add_executable(0014_LongestCommonPrefix src/0014_LongestCommonPrefix.cpp)
add_executable(0015_3Sum src/0015_3Sum.cpp)
add_executable(0016_3SumClosest src/0016_3SumClosest.cpp)
add_executable(0017_LetterCombinationsofaPhoneNumber src/0017_LetterCombinationsofaPhoneNumber.cpp)
add_executable(0018_4Sum src/0018_4Sum.cpp)
add_executable(0019_RemoveNthNodeFromEndofList src/0019_RemoveNthNodeFromEndofList.cpp)
add_executable(0020_ValidParentheses src/0020_ValidParentheses.cpp)
add_executable(0021_MergeTwoSortedLists src/0021_MergeTwoSortedLists.cpp)
add_executable(0022_GenerateParentheses src/0022_GenerateParentheses.cpp)
add_executable(0023_MergekSortedLists src/0023_MergekSortedLists.cpp)
add_executable(0024_SwapNodesinPairs src/0024_SwapNodesinPairs.cpp)
add_executable(0025_ReverseNodesink-Group src/0025_ReverseNodesink-Group.cpp)
add_executable(_0025_ReverseNodesInK-Group src/_0025_ReverseNodesInK-Group.cpp)
add_executable(0026_RemoveDuplicatesfromSortedArray src/0026_RemoveDuplicatesfromSortedArray.cpp)
add_executable(0027_RemoveElement src/0027_RemoveElement.cpp)
add_executable(0028_strStr src/0028_strStr.cpp)
add_executable(0029_DivideTwoIntegers src/0029_DivideTwoIntegers.cpp)
add_executable(0030_SubstringwithConcatenationofAllWords src/0030_SubstringwithConcatenationofAllWords.cpp)
add_executable(0031_NextPermutation src/0031_NextPermutation.cpp)
add_executable(0032_LongestValidParentheses src/0032_LongestValidParentheses.cpp)
add_executable(0033_SearchinRotatedSortedArray src/0033_SearchinRotatedSortedArray.cpp)
add_executable(0034_FindFirstandLastPositionofElementinSortedArray src/0034_FindFirstandLastPositionofElementinSortedArray.cpp)
add_executable(0035_SearchInsertPosition src/0035_SearchInsertPosition.cpp)
add_executable(0036_ValidSudoku src/0036_ValidSudoku.cpp)
add_executable(0037_SudokuSolver src/0037_SudokuSolver.cpp)
add_executable(0038_CountandSay src/0038_CountandSay.cpp)
add_executable(0039_CombinationSum src/0039_CombinationSum.cpp)
add_executable(0040_CombinationSumII src/0040_CombinationSumII.cpp)
add_executable(0041_FirstMissingPositive src/0041_FirstMissingPositive.cpp)
add_executable(0042_TrappingRainWater src/0042_TrappingRainWater.cpp)
add_executable(0043_MultiplyStrings src/0043_MultiplyStrings.cpp)
add_executable(0044_WildcardMatching src/0044_WildcardMatching.cpp)
add_executable(0045_JumpGameII src/0045_JumpGameII.cpp)
add_executable(0046_Permutations src/0046_Permutations.cpp)
add_executable(0047_PermutationsII src/0047_PermutationsII.cpp)
add_executable(0048_RotateImage src/0048_RotateImage.cpp)
add_executable(0049_GroupAnagrams src/0049_GroupAnagrams.cpp)
add_executable(0050_Pow_x_n src/0050_Pow_x_n.cpp)
add_executable(0051_N-Queens src/0051_N-Queens.cpp)
add_executable(0052_N-QueensII src/0052_N-QueensII.cpp)
add_executable(0053_MaximumSubarray src/0053_MaximumSubarray.cpp)
add_executable(0054_SpiralMatrix src/0054_SpiralMatrix.cpp)
add_executable(0055_JumpGame src/0055_JumpGame.cpp)
add_executable(0056_MergeIntervals src/0056_MergeIntervals.cpp)
add_executable(0057_InsertInterval src/0057_InsertInterval.cpp)
add_executable(0058_LengthofLastWord src/0058_LengthofLastWord.cpp)
add_executable(0059_SpiralMatrixII src/0059_SpiralMatrixII.cpp)
add_executable(0060_PermutationSequence src/0060_PermutationSequence.cpp)
add_executable(0061_RotateList src/0061_RotateList.cpp)
add_executable(0062_UniquePaths src/0062_UniquePaths.cpp)
add_executable(0063_UniquePathsII src/0063_UniquePathsII.cpp)
add_executable(0064_MinimumPathSum src/0064_MinimumPathSum.cpp)
#add_executable(0065_ValidNumber src/0065_ValidNumber.cpp)
add_executable(0066_PlusOne src/0066_PlusOne.cpp)
add_executable(0067_AddBinary src/0067_AddBinary.cpp)

add_executable(0100_SameTree src/0100_SameTree.cpp)

add_executable(0104_MaximumDepthofBinaryTree src/0104_MaximumDepthofBinaryTree.cpp)

add_executable(0121_BestTimetoBuyandSellStock src/0121_BestTimetoBuyandSellStock.cpp)

add_executable(0133_CloneGraph src/0133_CloneGraph.cpp)

add_executable(0152_MaximumProductSubarray src/0152_MaximumProductSubarray.cpp)

add_executable(0167_TwoSumII-InputArrayIsSorted src/0167_TwoSumII-InputArrayIsSorted.cpp)

add_executable(0217_ContainsDuplicate src/0217_ContainsDuplicate.cpp)

add_executable(0238_ProductofArrayExceptSelf src/0238_ProductofArrayExceptSelf.cpp)

add_executable(0259_3SumSmaller src/0259_3SumSmaller.cpp)

add_executable(0347_TopKFrequentElements src/0347_TopKFrequentElements.cpp)
add_executable(0371_SumofTwoIntegers src/0371_SumofTwoIntegers.cpp)
add_executable(0415_AddStrings src/0415_AddStrings.cpp)
add_executable(0445_AddTwoNumbersII src/0445_AddTwoNumbersII.cpp)
add_executable(0989_AddtoArray-FormofInteger src/0989_AddtoArray-FormofInteger.cpp)
add_executable(1634_AddTwoPolynomialsRepresentedasLinkedLists src/1634_AddTwoPolynomialsRepresentedasLinkedLists.cpp)

add_executable(test.cpp src/test.cpp)

# for i in `ls | cut -d '.' -f1`; do echo 'add_executable('$i' src/'$i'.cpp)'; done


#For the shared library:
#set ( PROJECT_LINK_LIBS libtest.so )
#link_directories( cmake/shared/build )

#For the static library:
#set ( PROJECT_LINK_LIBS libtest.a )
#link_directories( cmake/static/build )

#Bring the headers, such as queue.h into the project
#       include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCE src/test.cpp)

#However, the file(GLOB...) allows for wildcard additions:
#       file(GLOB SOURCE "src/*.cpp")

#       add_executable(${PROJECT_NAME} ${SOURCE})
#target_link_libraries(libtest ${PROJECT_LINK_LIBS} )