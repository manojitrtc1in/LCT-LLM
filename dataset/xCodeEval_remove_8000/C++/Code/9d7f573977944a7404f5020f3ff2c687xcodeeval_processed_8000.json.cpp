

using namespace std;

const int SegmentLen = 200000;

int Precalculated[] = {
0 , 8978 ,7923 ,7622 ,7393 ,7260 ,7254 ,7086 ,7007 ,6966 ,6928 ,6868 ,6770 ,6823 ,6730 ,6676 ,6755 ,6656 ,6575 ,6642 ,6591 ,6618 ,6498 ,6547 ,6509 ,6519 ,6423 ,6431 ,6445 ,6407 ,6433 ,6399 ,6391 ,6340 ,6381 ,6417 ,6320 ,6287 ,6273 ,6341 ,6278 ,6254 ,6257 ,6285 ,6322 ,6223 ,6225 ,6253 ,6234 ,6194 ,6174 ,6213 ,6157 ,6188 ,6170 ,6171 ,6181 ,6178 ,6196 ,6182 ,6176 ,6094 ,6201 ,6045 ,6166 ,6070 ,6091 ,6093 ,6065 ,6083 ,6073 ,6041 ,6120 ,6043 ,6072 ,6025 ,6018 ,5949 ,6009 ,6057 ,6106 ,5984 ,6024 ,6047 ,5981 ,6051 ,5960 ,6032 ,6021 ,5994 ,5995 ,5942 ,6003 ,5909 ,6008 ,5992 ,5989 ,5938 ,5935 ,5968 ,5984 ,5917 ,5880 ,5961 ,5928 ,5914 ,5905 ,5994 ,5906 ,5928 ,5986 ,5836 ,5855 ,5932 ,5876 ,5907 ,5935 ,5909 ,5866 ,5852 ,5860 ,5870 ,5962 ,5862 ,5884 ,5858 ,5857 ,5838 ,5837 ,5894 ,5848 ,5840 ,5884 ,5891 ,5855 ,5866 ,5830 ,5828 ,5853 ,5797 ,5842 ,5844 ,5828 ,5837 ,5834 ,5829 ,5774 ,5872 ,5778 ,5771 ,5899 ,5824 ,5849 ,5842 ,5793 ,5783 ,5753 ,5783 ,5789 ,5766 ,5784 ,5792 ,5734 ,5775 ,5781 ,5791 ,5788 ,5778 ,5777 ,5760 ,5799 ,5654 ,5722 ,5779 ,5712 ,5786 ,5709 ,5809 ,5721 ,5808 ,5682 ,5742 ,5780 ,5801 ,5715 ,5711 ,5823 ,5720 ,5672 ,5725 ,5747 ,5801 ,5771 ,5680 ,5779 ,5723 ,5708 ,5744 ,5740 ,5741 ,5662 ,5705 ,5726 ,5711 ,5775 ,5667 ,5724 ,5656 ,5711 ,5684 ,5642 ,5688 ,5750 ,5644 ,5663 ,5647 ,5684 ,5672 ,5742 ,5620 ,5771 ,5652 ,5658 ,5678 ,5694 ,5673 ,5604 ,5737 ,5668 ,5674 ,5632 ,5610 ,5705 ,5624 ,5720 ,5727 ,5645 ,5642 ,5682 ,5663 ,5681 ,5666 ,5643 ,5672 ,5609 ,5666 ,5643 ,5663 ,5665 ,5621 ,5666 ,5628 ,5605 ,5681 ,5644 ,5611 ,5579 ,5693 ,5609 ,5590 ,5609 ,5650 ,5591 ,5593 ,5640 ,5596 ,5584 ,5649 ,5559 ,5601 ,5659 ,5628 ,5555 ,5629 ,5586 ,5635 ,5628 ,5579 ,5555 ,5646 ,5627 ,5702 ,5531 ,5566 ,5650 ,5522 ,5578 ,5669 ,5615 ,5542 ,5613 ,5556 ,5616 ,5590 ,5563 ,5567 ,5565 ,5502 ,5605 ,5602 ,5625 ,5565 ,5605 ,5607 ,5626 ,5573 ,5496 ,5564 ,5537 ,5549 ,5567 ,5636 ,5585 ,5508 ,5574 ,5544 ,5589 ,5549 ,5533 ,5612 ,5585 ,5604 ,5617 ,5501 ,5549 ,5560 ,5583 ,5540 ,5589 ,5577 ,5532 ,5600 ,5555 ,5548 ,5569 ,5511 ,5507 ,5601 ,5587 ,5516 ,5583 ,5512 ,5557 ,5560 ,5580 ,5507 ,5590 ,5526 ,5546 ,5548 ,5489 ,5556 ,5505 ,5569 ,5496 ,5485 ,5534 ,5543 ,5565 ,5461 ,5557 ,5537 ,5542 ,5549 ,5555 ,5540 ,5459 ,5530 ,5535 ,5521 ,5489 ,5459 ,5563 ,5537 ,5526 ,5503 ,5489 ,5536 ,5584 ,5509 ,5562 ,5491 ,5476 ,5509 ,5489 ,5545 ,5529 ,5525 ,5466 ,5458 ,5480 ,5500 ,5529 ,5485 ,5497 ,5437 ,5512 ,5467 ,5507 ,5525 ,5432 ,5497 ,5540 ,5476 ,5486 ,5499 ,5560 ,5446 ,5510 ,5508 ,5554 ,5452 ,5461 ,5494 ,5494 ,5553 ,5392 ,5449 ,5506 ,5468 ,5633 ,5413 ,5491 ,5488 ,5443 ,5492 ,5434 ,5504 ,5537 ,5477 ,5395 ,5502 ,5458 ,5487 ,5402 ,5455 ,5509 ,5469 ,5483 ,5493 ,5518 ,5454 ,5494 ,5398 ,5516 ,5464 ,5487 ,5475 ,5446 ,5408 ,5450 ,5412 ,5515 ,5466 ,5419 ,5407 ,5455 ,5513 ,5342 ,5466 ,5451 ,5489 ,5459 ,5466 ,5507 ,5424 ,5429 ,5453 ,5430 ,5374 ,5503 ,5480 ,5382 ,5462 ,5448 ,5536 ,5396 ,5443 ,5505 ,5400 ,5484 ,5453 ,5396 ,5422 ,5480 ,5448 ,5422 ,5399 ,5470 ,5417 ,5459 ,5413 ,5411 ,5471 ,5384 ,5407 ,5452 ,5401 ,5434 ,5412 ,5444 ,5435 ,5384 ,5413 ,5436 ,5433 ,5420 ,5427 ,5381 ,5431 ,5438 ,5415 ,5518 ,5399 ,5412 ,5434 ,5359 ,5398 ,5413 ,5380 ,5471 ,5429 ,5468 ,5404 ,5394 ,5412 ,5408 ,5426 ,5415 ,5389 ,5375 ,5436 ,5373 ,5437 ,5358 ,5371 ,5493 ,5451 ,5364 ,5461 ,5317 ,5420 ,5426 ,5447 ,5446 ,5404 ,5437 ,5378 ,5424 ,5430 ,5464 ,5345 ,5333 ,5385 ,5438 ,5416 ,5403 ,5388 ,5372 ,5466 ,5445 ,5465 ,5397 ,5319 ,5453 ,5342 ,5430 ,5352 ,5340 ,5346 ,5324 ,5381 ,5382 ,5327 ,5476 ,5339 ,5399 ,5387 ,5400 ,5378 ,5364 ,5389 ,5410 ,5310 ,5327 ,5391 ,5348 ,5419 ,5411 ,5347 ,5367 ,5434 ,5373 ,5408 ,5296 ,5370 ,5408 ,5389 ,5401 ,5363 ,5364 ,5328 ,5336 ,5355 ,5378 ,5399 ,5413 ,5325 ,5423 ,5307 ,5355 ,5348 ,5370 ,5358 ,5397 ,5406 ,5413 ,5396 ,5371 ,5366 ,5388 ,5348 ,5412 ,5310 ,5398 ,5363 ,5351 ,5367 ,5320 ,5385 ,5365 ,5372 ,5325 ,5385 ,5328 ,5378 ,5404 ,5344 ,5374 ,5376 ,5359 ,5374 ,5335 ,5361 ,5443 ,5399 ,5362 ,5329 ,5397 ,5418 ,5275 ,5284 ,5346 ,5284 ,5416 ,5376 ,5336 ,5419 ,5371 ,5360 ,5330 ,5349 ,5357 ,5377 ,5328 ,5303 ,5411 ,5287 ,5362 ,5294 ,5355 ,5332 ,5390 ,5361 ,5347 ,5354 ,5355 ,5308 ,5294 ,5342 ,5291 ,5304 ,5321 ,5404 ,5353 ,5289 ,5272 ,5364 ,5391 ,5372 ,5206 ,5319 ,5271 ,5350 ,5296 ,5389 ,5358 ,5329 ,5419 ,5364 ,5366 ,5376 ,5271 ,5312 ,5275 ,5305 ,5260 ,5406 ,5312 ,5369 ,5321 ,5341 ,5377 ,5250 ,5328 ,5310 ,5334 ,5396 ,5306 ,5344 ,5337 ,5343 ,5382 ,5297 ,5309 ,5308 ,5331 ,5327 ,5308 ,5300 ,5366 ,5330 ,5328 ,5320 ,5324 ,5340 ,5313 ,5334 ,5353 ,5233 ,5326 ,5301 ,5298 ,5328 ,5291 ,5281 ,5310 ,5313 ,5312 ,5329 ,5299 ,5298 ,5282 ,5297 ,5308 ,5232 ,5300 ,5313 ,5279 ,5331 ,5332 ,5245 ,5197 ,5289 ,5333 ,5274 ,5314 ,5278 ,5348 ,5358 ,5319 ,5322 ,5282 ,5286 ,5251 ,5336 ,5274 ,5263 ,5373 ,5254 ,5292 ,5395 ,5302 ,5309 ,5336 ,5300 ,5207 ,5329 ,5349 ,5237 ,5293 ,5268 ,5320 ,5183 ,5250 ,5318 ,5303 ,5241 ,5363 ,5269 ,5307 ,5283 ,5286 ,5326 ,5237 ,5338 ,5366 ,5214 ,5299 ,5274 ,5246 ,5268 ,5335 ,5296 ,5312 ,5257 ,5276 ,5320 ,5320 ,5349 ,5328 ,5223 ,5324 ,5268 ,5268 ,5269 ,5226 ,5276 ,5289 ,5234 ,5329 ,5200 ,5329 ,5301 ,5261 ,5254 ,5292 ,5246 ,5290 ,5257 ,5313 ,5260 ,5280 ,5257 ,5302 ,5279 ,5374 ,5313 ,5318 ,5235 ,5229 ,5339 ,5272 ,5262 ,5190 ,5283 ,5301 ,5308 ,5262 ,5269 ,5232 ,5317 ,5282 ,5262 ,5276 ,5253 ,5321 ,5302 ,5301 ,5230 ,5280 ,5271 ,5265 ,5268 ,5233 ,5269 ,5280 ,5287 ,5308 ,5218 ,5266 ,5227 ,5306 ,5229 ,5294 ,5275 ,5287 ,5295 ,5227 ,5261 ,5320 ,5307 ,5225 ,5252 ,5279 ,5285 ,5290 ,5286 ,5255 ,5349 ,5289 ,5255 ,5229 ,5268 ,5234 ,5182 ,5232 ,5317 ,5217 ,5284 ,5292 ,5287 ,5167 ,5201 ,5275 ,5198 ,5283 ,5210 ,5264 ,5272 ,5229 ,5254 ,5309 ,5277 ,5300 ,5250 ,5294 ,5272 ,5187 ,5220 ,5278 ,5290 ,5201 ,5243 ,5247 ,5287 ,5297 ,5253 ,5239 ,5199 ,5253 ,5334 ,5181 ,5241 ,5290 ,5177 ,5331 ,5265 ,5252 ,5245 ,5302 ,5229 ,5237 ,5159 ,5160 ,5156 ,5265 ,5218 ,5236 ,5195 ,5196 ,5213 ,5245 ,5262 ,5292 ,5281 ,5284 ,5161 ,5264 ,5275 ,5242 ,5243 ,5240 ,5217 ,5258 ,5289 ,5258 ,5181 ,5247 ,5271 ,5226 ,5217 ,5209 ,5265 ,5176 ,5232 ,5178 ,5204 ,5200 ,5194 ,5258 ,5193 ,5245 ,5265 ,5289 ,5147 ,5182 ,5335 ,5206 ,5172 ,5295 ,5350 ,5163 ,5260 ,5200 ,5195 ,5329 ,5241 ,5176 ,5233 ,5289 ,5280 ,5229 ,5212 ,5172 ,5214 ,5240 ,5286 ,5195 ,5247 ,5255 ,5190 ,5178 ,5282 ,5230 ,5257 ,5174 ,5214 ,5171 ,5254 ,5188 ,5237 ,5211 ,5245 ,5190 ,5262 ,5160 ,5261 ,5264 ,5205 ,5162 ,5187 ,5175 ,5204 ,5254 ,5179 ,5178 ,5225 ,5266 ,5314 ,5185 ,5260 ,5239 ,5170 ,5172 ,5197 ,5296 ,5265 ,5205 ,5217 ,5242 ,5167 ,5267 ,5235 ,5234 ,5265 ,5209 ,5223 ,5215 ,5185 ,5225 ,5245 ,5158 ,5177 ,5255 ,5260 ,5269 ,5224 ,5215 ,5220 ,5245 ,5262 ,5251 ,5192 ,5192 ,5197 ,5196 ,5244 ,5121 ,5227 ,5160 ,5271 ,5174 ,5143 ,5217 ,5161 ,5188 ,5258 ,5200 ,5163 ,5190 ,5255 ,5251 ,5154 ,5163 ,5171 ,5220 ,5247 ,5158 ,5261 ,5159 ,5255 ,5160 ,5274 ,5233 ,5192 ,5213 ,5153 ,5304 ,5196 ,5105 ,5192 ,5282 ,5195 ,5160 ,5329 ,5205 ,5107 ,5169 ,5210 ,5222 ,5205 ,5174 ,5192 ,5285 ,5234 ,5246 ,5211 ,5110 ,5068 ,5178 ,5203 ,5142 ,5136 ,5272 ,5177 ,5203 ,5142 ,5198 ,5155 ,5205 ,5228 ,5161 ,5223 ,5235 ,5109 ,5188 ,5189 ,5179 ,5217 ,5247 ,5173 ,5194 ,5191 ,5249 ,5194 ,5134 ,5126 ,5220 ,5204 ,5141 ,5189 ,5131 ,5179 ,5209 ,5231 ,5158 ,5235 ,5254 ,5133 ,5170 ,5245 ,5176 ,5175 ,5244 ,5205 ,5173 ,5181 ,5241 ,5145 ,5185 ,5246 ,5197 ,5134 ,5264 ,5167 ,5135 ,5183 ,5181 ,5165 ,5144 ,5196 ,5252 ,5249 ,5114 ,5202 ,5225 ,5200 ,5196 ,5118 ,5199 ,5116 ,5117 ,5154 ,5125 ,5200 ,5105 ,5180 ,5194 ,5201 ,5203 ,5160 ,5151 ,5212 ,5198 ,5268 ,5188 ,5206 ,5202 ,5156 ,5148 ,5133 ,5140 ,5185 ,5146 ,5190 ,5177 ,5109 ,5190 ,5111 ,5173 ,5151 ,5254 ,5156 ,5189 ,5193 ,5182 ,5165 ,5109 ,5161 ,5166 ,5171 ,5164 ,5117 ,5239 ,5262 ,5103 ,5151 ,5145 ,5144 ,5124 ,5229 ,5085 ,5177 ,5108 ,5157 ,5181 ,5228 ,5250 ,5112 ,5144 ,5167 ,5189 ,5189 ,5192 ,5226 ,5145 ,5179 ,5148 ,5194 ,5158 ,5186 ,5147 ,5123 ,5128 ,5274 ,5190 ,5211 ,5134 ,5091 ,5207 ,5144 ,5175 ,5211 ,5213 ,5162 ,5145 ,5198 ,5190 ,5071 ,5125 ,5182 ,5174 ,5189 ,5182 ,5224 ,5200 ,5147 ,5175 ,5112 ,5136 ,5207 ,5196 ,5242 ,5118 ,5208 ,5229 ,5148 ,5096 ,5182 ,5112 ,5189 ,5195 ,5118 ,5128 ,5229 ,5139 ,5239 ,5174 ,5190 ,5186 ,5153 ,5095 ,5098 ,5125 ,5156 ,5159 ,5150 ,5185 ,5103 ,5170 ,5162 ,5113 ,5238 ,5128 ,5222 ,5141 ,5188 ,5070 ,5098 ,5126 ,5111 ,5217 ,5181 ,5132 ,5131 ,5089 ,5137 ,5140 ,5224 ,5116 ,5120 ,5186 ,5153 ,5081 ,5117 ,5101 ,5172 ,5202 ,5147 ,5184 ,5190 ,5152 ,5143 ,5188 ,5146 ,5078 ,5179 ,5167 ,5127 ,5173 ,5099 ,5221 ,5084 ,5151 ,5157 ,5104 ,5139 ,5187 ,5183 ,5122 ,5070 ,5136 ,5142 ,5114 ,5125 ,5129 ,5125 ,5114 ,5229 ,5129 ,5110 ,5102 ,5236 ,5081 ,5077 ,5142 ,5164 ,5173 ,5178 ,5123 ,5059 ,5163 ,5132 ,5107 ,5136 ,5130 ,5170 ,5174 ,5143 ,5126 ,5123 ,5181 ,5111 ,5149 ,5140 ,5021 ,5208 ,5133 ,5146 ,5107 ,5112 ,5130 ,5084 ,5107 ,5159 ,5242 ,5131 ,5145 ,5097 ,5155 ,5130 ,5160 ,5105 ,5164 ,5176 ,4995 ,5115 ,5172 ,5192 ,5114 ,5113 ,5177 ,5083 ,5173 ,5209 ,5196 ,5117 ,5036 ,5146 ,5185 ,5124 ,5174 ,5070 ,5097 ,5054 ,5170 ,5158 ,5108 ,5135 ,5121 ,5169 ,5120 ,5156 ,5153 ,5139 ,5074 ,5112 ,5153 ,5123 ,5090 ,5086 ,5084 ,5175 ,5208 ,5063 ,5103 ,5173 ,5072 ,5131 ,5160 ,5114 ,5132 ,5178 ,5043 ,5054 ,5067 ,5081 ,5130 ,5164 ,5088 ,5194 ,5149 ,5159 ,5094 ,5160 ,5078 ,5129 ,5116 ,5073 ,5178 ,5103 ,5113 ,5115 ,5129 ,5119 ,5119 ,5150 ,5112 ,5068 ,5160 ,5140 ,5195 ,5169 ,5140 ,5145 ,5105 ,5109 ,5116 ,5130 ,5128 ,5099 ,5171 ,5098 ,5064 ,5112 ,5143 ,5080 ,5093 ,5110 ,5104 ,5205 ,5107 ,5208 ,5109 ,5031 ,5158 ,5123 ,5098 ,5138 ,5142 ,5069 ,5139 ,5063 ,5068 ,5164 ,5060 ,5035 ,5095 ,5089 ,5117 ,5100 ,5165 ,5218 ,5083 ,5153 ,5129 ,5104 ,5067 ,5134 ,5068 ,5099 ,5168 ,5078 ,5113 ,5148 ,5069 ,5120 ,5125 ,5138 ,5141 ,5056 ,5123 ,5134 ,5115 ,5086 ,5092 ,5077 ,5120 ,5116 ,5119 ,5116 ,5038 ,5041 ,5073 ,5090 ,5099 ,5151 ,5111 ,5145 ,5173 ,5128 ,5023 ,5081 ,5125 ,5104 ,5117 ,5072 ,5074 ,5096 ,5075 ,5086 ,5144 ,5132 ,5069 ,5100 ,5024 ,5113 ,5082 ,5223 ,5102 ,5082 ,5033 ,5083 ,5070 ,5099 ,5086 ,5147 ,5136 ,5084 ,5090 ,5188 ,5056 ,5098 ,5087 ,5109 ,5062 ,4994 ,5151 ,5168 ,5120 ,5096 ,5127 ,5082 ,5068 ,5095 ,5079 ,5125 ,5122 ,5109 ,5112 ,5087 ,5076 ,5095 ,5032 ,5140 ,5059 ,5139 ,5038 ,5161 ,5109 ,5149 ,5042 ,5138 ,5201 ,5094 ,5040 ,5146 ,5035 ,5090 ,5064 ,5111 ,5105 ,5040 ,5130 ,5165 ,5150 ,5082 ,5031 ,5111 ,5056 ,5147 ,5034 ,5123 ,5104 ,5018 ,5104 ,5028 ,5129 ,5048 ,5140 ,5139 ,5091 ,5078 ,5057 ,5124 ,5114 ,5047 ,5072 ,5062 ,5108 ,5182 ,5057 ,5109 ,5070 ,5125 ,5025 ,5051 ,5238 ,5129 ,5080 ,5088 ,5078 ,4983 ,5116 ,5032 ,5141 ,5049 ,5166 ,5118 ,5039 ,5091 ,5103 ,5107 ,5041 ,5101 ,5051 ,5106 ,5069 ,5107 ,5083 ,5051 ,5129 ,5023 ,5009 ,5177 ,5076 ,5055 ,5038 ,5075 ,5131 ,5029 ,5028 ,5046 ,5107 ,5028 ,5151 ,5012 ,5063 ,5089 ,5109 ,5085 ,5135 ,5064 ,5060 ,5090 ,5107 ,5044 ,5079 ,5063 ,5079 ,5080 ,5046 ,5134 ,5112 ,5056 ,5033 ,5064 ,5072 ,5125 ,5099 ,5105 ,5101 ,5088 ,5053 ,5083 ,5077 ,5079 ,5014 ,5002 ,5089 ,5078 ,5062 ,5071 ,5009 ,5065 ,5120 ,5042 ,5143 ,5062 ,5076 ,5121 ,5041 ,5079 ,5030 ,5156 ,5077 ,5045 ,5071 ,5038 ,5051 ,5017 ,5010 ,5127 ,5070 ,5092 ,5067 ,5086 ,5061 ,5184 ,5036 ,5110 ,5092 ,5085 ,5039 ,5124 ,5112 ,5109 ,5037 ,5078 ,5021 ,5129 ,5109 ,5009 ,5053 ,5123 ,5122 ,5041 ,5126 ,5083 ,5071 ,5084 ,4991 ,5123 ,5084 ,5032 ,5027 ,5157 ,5049 ,5113 ,4998 ,5091 ,5027 ,5032 ,5043 ,5087 ,5039 ,5112 ,5083 ,5018 ,5097 ,5051 ,5027 ,5022 ,5020 ,5078 ,5126 ,5045 ,5004 ,5086 ,5091 ,5040 ,5113 ,4987 ,5051 ,5067 ,5080 ,5114 ,5037 ,5173 ,4956 ,5108 ,5056 ,5096 ,5060 ,5088 ,5063 ,5044 ,5025 ,5098 ,5053 ,5009 ,5097 ,5062 ,5136 ,5111 ,5004 ,5099 ,5081 ,5104 ,5124 ,5157 ,5102 ,5052 ,5076 ,5044 ,5061 ,5056 ,5091 ,5067 ,5011 ,5051 ,5050 ,5072 ,5079 ,5056 ,5026 ,5120 ,5023 ,5084 ,5064 ,4982 ,5089 ,5029 ,5121 ,5007 ,5065 ,5056 ,5069 ,5075 ,4996 ,5145 ,5068 ,5000 ,5052 ,5068 ,4998 ,5079 ,4994 ,5087 ,5061 ,5039 ,5089 ,5025 ,5085 ,5134 ,5073 ,5085 ,5129 ,5117 ,5011 ,5117 ,5094 ,5070 ,4995 ,5078 ,5080 ,5086 ,5051 ,5048 ,5005 ,4982 ,5030 ,5025 ,5096 ,5088 ,4979 ,5034 ,5099 ,4996 ,5073 ,5087 ,5057 ,5001 ,5065 ,5050 ,5050 ,5010 ,5046 ,5053 ,5128 ,5079 ,5029 ,5026 ,4999 ,5092 ,5036 ,5094 ,4999 ,5068 ,5026 ,4942 ,5023 ,5088 ,5062 ,5086 ,5090 ,5040 ,5033 ,5043 ,5118 ,5029 ,5112 ,5052 ,5020 ,5020 ,5081 ,5023 ,5057 ,5095 ,5079 ,5018 ,5038 ,4972 ,5134 ,5020 ,5005 ,5017 ,5128 ,5050 ,5096 ,5051 ,5077 ,5106 ,4959 ,5036 ,5092 ,5096 ,5061 ,5051 ,5030 ,5101 ,4965 ,5003 ,5046 ,5078 ,5080 ,5060 ,5050 ,5001 ,5089 ,5012 ,5097 ,5022 ,5001 ,5151 ,5107 ,4983 ,5006 ,4944 ,5075 ,5012 ,5096 ,4993 ,5048 ,5040 ,5015 ,5012 ,5078 ,5077 ,4976 ,5034 ,5030 ,5059 ,5061 ,5044 ,5005 ,5003 ,5071 ,5022 ,5028 ,5048 ,4993 ,5037 ,5080 ,5092 ,5029 ,5056 ,5037 ,5077 ,5035 ,5069 ,5017 ,5054 ,5035 ,4948 ,5011 ,5046 ,5023 ,5011 ,5104 ,4971 ,5112 ,5015 ,5090 ,5028 ,5036 ,5040 ,5098 ,4956 ,5039 ,5034 ,5029 ,4989 ,5076 ,5006 ,5087 ,5043 ,5044 ,5092 ,4980 ,5039 ,4989 ,5074 ,5086 ,4988 ,4989 ,5062 ,5090 ,4972 ,5103 ,5048 ,4972 ,5090 ,4953 ,5058 ,5039 ,5023 ,5026 ,5018 ,5035 ,5073 ,5016 ,5094 ,5135 ,4982 ,5036 ,5051 ,5009 ,4998 ,5059 ,5036 ,5066 ,4975 ,5005 ,5025 ,4927 ,5063 ,5051 ,5007 ,5049 ,5047 ,5046 ,5066 ,4969 ,5012 ,5033 ,4974 ,5070 ,5019 ,5043 ,5025 ,4973 ,4995 ,5036 ,5037 ,5048 ,4999 ,5029 ,5075 ,4991 ,5056 ,5017 ,5094 ,4960 ,5126 ,5022 ,4999 ,5004 ,5065 ,4983 ,5000 ,5014 ,5134 ,4963 ,4987 ,5046 ,4962 ,5006 ,5032 ,5015 ,4931 ,5038 ,4997 ,4990 ,5022 ,5007 ,5048 ,4981 ,5056 ,4972 ,5033 ,5068 ,5041 ,4977 ,5108 ,5045 ,4980 ,5107 ,5034 ,4897 ,5045 ,5038 ,5070 ,5084 ,5014 ,5076 ,4987 ,4994 ,5083 ,5056 ,5047 ,5084 ,5007 ,5028 ,5063 ,5034 ,4988 ,5043 ,5006 ,5055 ,5029 ,4995 ,5035 ,5073 ,5061 ,5009 ,5012 ,4984 ,5045 ,4984 ,5061 ,5063 ,5042 ,4949 ,5025 ,5005 ,5058 ,5046 ,5008 ,5052 ,4954 ,5023 ,5023 ,4971 ,5029 ,4959 ,5088 ,5007 ,5101 ,5042 ,4934 ,5088 ,5019 ,4996 ,5045 ,4992 ,5049 ,4947 ,5059 ,4991 ,5007 ,5029 ,5011 ,4980 ,5039 ,5036 ,5004 ,5061 ,5043 ,5009 ,4992 ,4966 ,5020 ,5023 ,5062 ,4978 ,5043 ,5056 ,5036 ,5042 ,5040 ,5020 ,5054 ,5010 ,4993 ,4969 ,4988 ,4991 ,4991 ,4977 ,5023 ,4969 ,5001 ,5044 ,4998 ,5000 ,4979 ,5048 ,4970 ,5004 ,4998 ,4999 ,4978 ,5062 ,5052 ,5007 ,5020 ,5015 ,5001 ,5012 ,5016 ,4967 ,5091 ,4999 ,4996 ,5038 ,5050 ,5017 ,5018 ,4982 ,4939 ,5053 ,5001 ,5024 ,5022 ,5034 ,4995 ,4960 ,5005 ,5073 ,5046 ,4989 ,4972 ,4969 ,5076 ,4936 ,4960 ,5045 ,5045 ,4977 ,4990 ,4953 ,5004 ,5029 ,5010 ,4955 ,5035 ,5034 ,4967 ,5013 ,5056 ,4980 ,5068 ,5022 ,4998 ,5049 ,4999 ,5075 ,4986 ,4993 ,4901 ,4996 ,5007 ,5020 ,4941 ,5020 ,4979 ,5075 ,4961 ,5040 ,5000 ,4958 ,4980 ,4944 ,5015 ,4950 ,4977 ,4979 ,5034 ,5052 ,4932 ,5065 ,5044 ,4981 ,5018 ,5034 ,4943 ,5017 ,5062 ,4986 ,5075 ,5003 ,5031 ,5006 ,4980 ,5050 ,5005 ,5001 ,5081 ,4959 ,4992 ,4963 ,4981 ,5000 ,4991 ,4990 ,5061 ,5031 ,4966 ,4898 ,4981 ,5007 ,5081 ,5028 ,5001 ,5119 ,4981 ,4981 ,4981 ,4987 ,5070 ,5016 ,4993 ,4958 ,4956 ,4949 ,5006 ,4973 ,4950 ,5039 ,5023 ,4940 ,5040 ,5013 ,4935 ,5013 ,4973 ,4991 ,5051 ,4950 ,4954 ,5007 ,5013 ,4997 ,5052 ,4974 ,5016 ,5018 ,4971 ,5037 ,5023 ,4932 ,4998 ,5060 ,4957 ,5040 ,4964 ,5086 ,4937 ,4964 ,5011 ,4953 ,5027 ,5040 ,4997 ,4963 ,4947 ,5018 ,4997 ,5115 ,4931 ,4971 ,4974 ,4953 ,4961 ,4986 ,5012 ,4995 ,5008 ,4963 ,5006 ,4937 ,5012 ,5002 ,5047 ,5023 ,4958 ,5025 ,4939 ,5008 ,5007 ,5015 ,5004 ,4995 ,4970 ,4952 ,5040 ,4930 ,4979 ,4959 ,4944 ,5030 ,4956 ,5010 ,5023 ,4929 ,4952 ,4964 ,4987 ,5048 ,4975 ,4965 ,5008 ,4964 ,4906 ,5006 ,4992 ,5002 ,5002 ,4965 ,5010 ,4927 ,4928 ,4973 ,4977 ,4966 ,4982 ,5038 ,4922 ,5116 ,5030 ,4946 ,5094 ,4990 ,5043 ,4939 ,4949 ,4905 ,5051 ,5090 ,4964 ,4974 ,5025 ,4961 ,4953 ,5012 ,5067 ,4990 ,4947 ,5016 ,4985 ,5019 ,5004 ,4936 ,4936 ,4946 ,4942 ,4958 ,5028 ,5108 ,4988 ,4976 ,5012 ,4989 ,4995 ,4981 ,5009 ,5011 ,4970 ,5060 ,4983 ,4926 ,4991 ,4952 ,4946 ,4948 ,4939 ,5037 ,4910 ,4964 ,4988 ,5022 ,5011 ,5012 ,5024 ,4961 ,5005 ,4969 ,4993 ,4999 ,4961 ,5044 ,4998 ,4970 ,5024 ,4956 ,5014 ,4962 ,5005 ,4913 ,4980 ,4879 ,5016 ,4973 ,4992 ,4967 ,4937 ,5026 ,5074 ,5005 ,4942 ,4942 ,5038 ,4987 ,5016 ,5007 ,5039 ,4944 ,4909 ,5000 ,4926 ,5000 ,5040 ,4939 ,4983 ,4961 ,5017 ,4938 ,5023 ,5027 ,4935 ,4985 ,4983 ,5019 ,4914 ,4956 ,4996 ,4917 ,4988 ,4994 ,4966 ,4949 ,5057 ,4961 ,5054 ,4982 ,4955 ,4978 ,4976 ,4973 ,5044 ,5022 ,4944 ,4978 ,5000 ,4877 ,4997 ,5040 ,4920 ,5032 ,4994 ,4960 ,4946 ,4961 ,4998 ,4959 ,5058 ,4999 ,4971 ,4961 ,4933 ,4952 ,4910 ,5039 ,4965 ,5052 ,4972 ,4991 ,4829 ,4998 ,5005 ,4991 ,5010 ,5006 ,4949 ,4997 ,4957 ,4972 ,4967 ,4989 ,5013 ,4917 ,5002 ,4985 ,4962 ,5025 ,5019 ,4955 ,4982 ,4892 ,4936 ,4979 ,5025 ,5023 ,4964 ,4982 ,4988 ,4921 ,4962 ,5033 ,4973 ,4971 ,4883 ,5024 ,5024 ,4898 ,4962 ,4991 ,4943 ,4966 ,5047 ,4947 ,4926 ,5012 ,4938 ,4980 ,4974 ,4967 ,4902 ,4937 ,4972 ,4953 ,4941 ,4986 ,4987 ,5060 ,4965 ,4946 ,5023 ,4921 ,4955 ,4978 ,5023 ,4993 ,4988 ,4951 ,5025 ,4999 ,4953 ,4883 ,5030 ,4960 ,4951 ,5000 ,4997 ,4941 ,4918 ,5011 ,4967 ,5023 ,5001 ,4917 ,5020 ,5000 ,5005 ,4979 ,4978 ,4919 ,4929 ,4987 ,4983 ,4947 ,4875 ,4976 ,5033 ,5000 ,4954 ,4937 ,4979 ,4929 ,5047 ,4913 ,5009 ,4892 ,4938 ,4914 ,5016 ,4959 ,4890 ,5055 ,5029 ,4942 ,4954 ,4938 ,4982 ,4921 ,4979 ,4930 ,4942 ,4945 ,4938 ,4966 ,5010 ,5030 ,4883 ,4937 ,4931 ,5030 ,4936 ,5086 ,4977 ,4939 ,5046 ,4897 ,4992 ,4926 ,4993 ,4918 ,4967 ,4955 ,4986 ,4880 ,4964 ,4981 ,5008 ,4947 ,4940 ,4959 ,4963 ,4985 ,4911 ,5025 ,4949 ,4949 ,4928 ,5040 ,4911 ,4996 ,4982 ,4954 ,4868 ,4863 ,4960 ,4944 ,5036 ,4933 ,4977 ,4972 ,4877 ,4917 ,4990 ,4927 ,4944 ,4970 ,4976 ,5018 ,4919 ,4974 ,4992 ,4977 ,4997 ,5043 ,4949 ,4902 ,4973 ,4975 ,4951 ,4965 ,5012 ,4938 ,5016 ,4931 ,4940 ,5025 ,4960 ,4947 ,4950 ,4977 ,4923 ,4927 ,4906 ,5019 ,4994 ,5015 ,4861 ,4909 ,5024 ,4946 ,4967 ,4978 ,4971 ,4988 ,4921 ,4937 ,4953 ,4994 ,5072 ,4930 ,4943 ,5000 ,4912 ,5009 ,4936 ,5016 ,4969 ,4925 ,4891 ,4976 ,5000 ,4874 ,4937 ,5019 ,4984 ,4904 ,4989 ,4930 ,4962 ,5001 ,4927 ,4963 ,4896 ,4918 ,5029 ,5042 ,4851 ,4915 ,4919 ,5006 ,4943 ,4909 ,4901 ,5043 ,4993 ,4943 ,4914 ,4934 ,5005 ,4997 ,4897 ,4904 ,4913 ,4923 ,4858 ,5012 ,5013 ,4990 ,4969 ,4925 ,4955 ,5022 ,4935 ,4989 ,4969 ,4863 ,5014 ,4970 ,4911 ,4930 ,5020 ,5020 ,4936 ,4990 ,4913 ,4922 ,4954 ,4891 ,4925 ,4911 ,4895 ,4996 ,4978 ,4993 ,4923 ,4954 ,4925 ,4985 ,4972 ,4938 ,4934 ,5030 ,5019 ,4944 ,4887 ,4883 ,5009 ,4932 ,4971 ,4970 ,4948 ,4953 ,4944 ,4956 ,4955 ,4971 ,4976 ,4965 ,4950 ,4897 ,4914 ,4975 ,4971 ,4971 ,4972 ,4908 ,4986 ,4986 ,4902 ,4908 ,5012 ,4907 ,4976 ,4941 ,4977 ,4932 ,4903 ,4921 ,4990 ,4912 ,5014 ,4966 ,4978 ,4958 ,4973 ,4922 ,4894 ,4926 ,4841 ,4959 ,4843 ,4962 ,5006 ,4915 ,4965 ,4925 ,4925 ,4941 ,4918 ,4912 ,4984 ,4947 ,5014 ,4996 ,4948 ,4870 ,4930 ,4904 ,4951 ,4957 ,4939 ,4991 ,4895 ,5027 ,5026 ,4861 ,4970 ,4907 ,4850 ,5003 ,4919 ,4987 ,4976 ,4963 ,5007 ,4846 ,4978 ,4963 ,4942 ,4935 ,4920 ,4965 ,4946 ,4896 ,4967 ,4957 ,4933 ,4947 ,4873 ,5022 ,4911 ,4928 ,4890 ,4930 ,5000 ,4879 ,4944 ,4892 ,4867 ,4788 ,4988 ,4939 ,4944 ,4971 ,4928 ,4882 ,4907 ,4876 ,4946 ,4983 ,4948 ,4903 ,4904 ,4937 ,5019 ,4883 ,4928 ,4919 ,4897 ,4960 ,4926 ,4858 ,4985 ,4830 ,4964 ,4962 ,4902 ,4996 ,4956 ,4904 ,4883 ,4959 ,4924 ,4890 ,4954 ,4986 ,4966 ,4937 ,4857 ,4993 ,4959 ,4921 ,4920 ,4880 ,5036 ,4959 ,4900 ,5002 ,5060 ,4886 ,4900 ,4989 ,4946 ,4910 ,4953 ,4945 ,4883 ,5006 ,4970 ,4958 ,4837 ,4974 ,4980 ,4981 ,4893 ,4913 ,4920 ,4932 ,4922 ,5003 ,4965 ,4972 ,4872 ,4940 ,4883 ,4961 ,4911 ,4965 ,4944 ,4874 ,4952 ,4947 ,4998 ,4893 ,4917 ,4926 ,4931 ,4851 ,4916 ,4920 ,4937 ,4925 ,4921 ,4905 ,4934 ,4930 ,5048 ,4868 ,4976 ,4934 ,4933 ,4961 ,4941 ,4941 ,4923 ,4845 ,4944 ,4926 ,4899 ,4966 ,4980 ,4890 ,4923 ,4971 ,4944 ,4965 ,4951 ,4873 ,4992 ,4921 ,4932 ,4903 ,4902 ,4967 ,4928 ,4956 ,4953 ,4895 ,4938 ,4912 ,4927 ,4918 ,4907 ,4897 ,4834 ,4979 ,4931 ,4927 ,4929 ,4991 ,4948 ,4997 ,4880 ,4909 ,5034 ,4910 ,4928 ,4961 ,4905 ,4893 ,4899 ,4971 ,4934 ,4931 ,4934 ,4860 ,4977 ,4938 ,4929 ,4935 ,4909 ,4960 ,4984 ,4923 ,4893 ,4900 ,4853 ,4960 ,4916 ,4851 ,4922 ,4864 ,4918 ,4881 ,4943 ,4973 ,4904 ,4941 ,4850 ,4937 ,4915 ,4963 ,4974 ,4929 ,4853 ,4933 ,4870 ,4920 ,4907 ,4936 ,4943 ,4914 ,4957 ,4926 ,4864 ,4934 ,4948 ,4962 ,4904 ,4949 ,4968 ,4914 ,4918 ,4961 ,4900 ,4894 ,4940 ,4959 ,4913 ,4924 ,4934 ,4899 ,4895 ,4960 ,4965 ,4935 ,4950 ,4992 ,4868 ,4981 ,4897 ,4881 ,4949 ,4920 ,4933 ,4930 ,4854 ,4959 ,4917 ,4916 ,4998 ,4978 ,4876 ,5001 ,4901 ,4852 ,4850 ,5008 ,4835 ,4916 ,4923 ,4934 ,4912 ,4908 ,4976 ,4910 ,4924 ,4936 ,4933 ,4941 ,4831 ,4848 ,4944 ,4971 ,4951 ,4914 ,4919 ,4953 ,4859 ,4909 ,4904 ,4902 ,4982 ,4902 ,4907 ,4936 ,4931 ,4920 ,4911 ,4782 ,4935 ,4949 ,4925 ,4887 ,4954 ,5035 ,4881 ,4995 ,4881 ,4833 ,5051 ,4900 ,4947 ,4852 ,4968 ,4957 ,4899 ,4874 ,4853 ,4951 ,4901 ,4920 ,4891 ,4886 ,4937 ,4972 ,4925 ,4887 ,4893 ,4882 ,4917 ,4930 ,4965 ,4879 ,4932 ,4888 ,4944 ,4940 ,4943 ,4899 ,4991 ,4971 ,4802 ,4963 ,4820 ,4966 ,4861 ,4974 ,4851 ,5020 ,4835 ,4938 ,4949 ,4901 ,4864 ,4936 ,4919 ,4903 ,4905 ,4972 ,4875 ,4934 ,4954 ,4867 ,4963 ,4923 ,4972 ,4909 ,4916 ,4943 ,4837 ,4961 ,4949 ,4888 ,4937 ,4910 ,4990 ,4866 ,4980 ,4925 ,4878 ,4822 ,5010 ,4929 ,4899 ,4875 ,4868 ,4924 ,4919 ,4934 ,4931 ,4926 ,4959 ,4932 ,4877 ,4936 ,4944 ,4907 ,4964 ,4951 ,4854 ,4879 ,4915 ,4889 ,4899 ,4950 ,4829 ,4842 ,4906 ,4886 ,4942 ,4868 ,4964 ,4919 ,4956 ,4963 ,4950 ,4861 ,4934 ,4925 ,4882 ,4870 ,4983 ,4899 ,4807 ,5010 ,4909 ,4921 ,4852 ,4890 ,4884 ,4967 ,4854 ,4909 ,4868 ,4960 ,4846 ,4949 ,4950 ,4844 ,4983 ,4843 ,4917 ,4936 ,4881 ,4860 ,4899 ,4964 ,4946 ,4906 ,4919 ,4869 ,4958 ,4946 ,4947 ,4837 ,4900 ,4906 ,4905 ,4969 ,4837 ,4987 ,4881 ,4864 ,4981 ,4818 ,4855 ,4940 ,4853 ,4997 ,4916 ,4859 ,4961 ,4895 ,4976 ,4954 ,4862 ,4885 ,4944 ,4916 ,4905 ,4929 ,4951 ,4899 ,4948 ,4895 ,4949 ,4944 ,4899 ,4940 ,4831 ,4886 ,4940 ,4837 ,4873 ,4952 ,4919 ,4921 ,4934 ,4880 ,4883 ,4931 ,4934 ,4934 ,4921 ,4911 ,4928 ,4848 ,4812 ,4904 ,4887 ,4853 ,4922 ,4921 ,4889 ,4854 ,4937 ,4895 ,4934 ,4846 ,4884 ,4874 ,4879 ,4809 ,4954 ,4917 ,4970 ,4881 ,4847 ,4905 ,4987 ,4938 ,4888 ,4876 ,4888 ,4983 ,4898 ,4936 ,4937 ,4871 ,4939 ,4910 ,4801 ,4920 ,5003 ,4862 ,4906 ,4957 ,4926 ,4931 ,4961 ,4857 ,4878 ,4844 ,4918 ,4894 ,4934 ,4922 ,4933 ,4876 ,4891 ,4888 ,4852 ,4961 ,4960 ,4925 ,4843 ,4836 ,4879 ,4953 ,4884 ,4837 ,4847 ,4942 ,4934 ,4841 ,4879 ,4958 ,4967 ,4947 ,4873 ,4925 ,4900 ,4868 ,4854 ,4906 ,4845 ,4852 ,4963 ,4878 ,4873 ,4854 ,4927 ,4853 ,4840 ,4938 ,4906 ,4985 ,4886 ,4868 ,4878 ,4863 ,4908 ,4911 ,4917 ,4800 ,4968 ,4924 ,4890 ,4882 ,4861 ,4936 ,4882 ,4855 ,4894 ,4901 ,4875 ,4945 ,4919 ,4899 ,4855 ,4858 ,4879 ,4863 ,4894 ,4892 ,4943 ,4982 ,4906 ,4849 ,4917 ,4888 ,4912 ,4906 ,4843 ,4887 ,4914 ,4878 ,4900 ,4880 ,4853 ,4928 ,4894 ,4890 ,4905 ,4898 ,4886 ,4917 ,4950 ,4960 ,4916 ,4884 ,4919 ,4912 ,4848 ,4888 ,4911 ,4899 ,4924 ,4919 ,4831 ,4932 ,4885 ,4909 ,4841 ,4922 ,4884 ,4798 ,4894 ,4862 ,4867 ,4854 ,4887 ,4872 ,4843 ,4844 ,4830 ,4824 ,4894 ,4963 ,4890 ,4889 ,4883 ,4880 ,4849 ,4846 ,4842 ,4863 ,4963 ,4812 ,4974 ,4949 ,4867 ,4847 ,4930 ,4923 ,4857 ,4941 ,4883 ,4848 ,4940 ,4924 ,4901 ,4886 ,4901 ,4994 ,4815 ,4953 ,4843 ,4869 ,4870 ,4819 ,4941 ,4832 ,4892 ,4892 ,4910 ,4932 ,4981 ,4951 ,4954 ,4983 ,4929 ,4828 ,4937 ,4858 ,4898 ,4863 ,4860 ,4959 ,4797 ,4887 ,4854 ,4861 ,4904 ,4793 ,4893 ,4935 ,4944 ,4880 ,4849 ,4897 ,4898 ,4920 ,4923 ,4893 ,4855 ,4883 ,4942 ,4951 ,4874 ,4879 ,4985 ,4891 ,4893 ,4956 ,4885 ,4853 ,4879 ,4890 ,4804 ,4896 ,4835 ,4928 ,4882 ,4862 ,4903 ,4947 ,4851 ,4874 ,4911 ,4873 ,4929 ,4887 ,4801 ,4892 ,4856 ,4950 ,4908 ,4922 ,4895 ,4923 ,4920 ,4872 ,4957 ,4914 ,4866 ,4893 ,4910 ,4906 ,4876 ,4914 ,4939 ,4841 ,4922 ,4906 ,4898 ,4871 ,4864 ,4889 ,4833 ,4905 ,4856 ,4900 ,4911 ,4975 ,4809 ,4866 ,4784 ,4881 ,4862 ,4930 ,4855 ,4878 ,4852 ,4861 ,4866 ,4940 ,4900 ,4843 ,4794 ,4904 ,4912 ,4811 ,4972 ,4867 ,4995 ,4877 ,4920 ,4843 ,4908 ,4891 ,4802 ,4890 ,4861 ,4893 ,4889 ,4944 ,4800 ,4903 ,4930 ,4889 ,4904 ,4870 ,4908 ,4881 ,4924 ,4872 ,4926 ,4878 ,4826 ,4884 ,4917 ,4911 ,4823 ,4927 ,4859 ,4885 ,4857 ,4902 ,4881 ,4890 ,4916 ,4887 ,4846 ,4955 ,4902 ,4910 ,4831 ,4893 ,4919 ,4875 ,4866 ,4910 ,4865 ,4887 ,4843 ,4925 ,4820 ,4918 ,4882 ,4881 ,4871 ,4861 ,4820 ,4964 ,4853 ,4955 ,4879 ,4914 ,4920 ,4967 ,4918 ,4850 ,4943 ,4853 ,4875 ,4928 ,4890 ,4921 ,4811 ,4958 ,4846 ,4869 ,4879 ,4912 ,4919 ,4912 ,4817 ,4815 ,4933 ,4907 ,4859 ,4894 ,4880 ,4867 ,4831 ,4917 ,4811 ,4952 ,4854 ,4923 ,4899 ,4850 ,4861 ,4928 ,4862 ,4934 ,4890 ,4829 ,4897 ,4866 ,4810 ,5006 ,4883 ,4909 ,4818 ,4876 ,4763 ,4839 ,4887 ,4824 ,4944 ,4927 ,4858 ,4845 ,4895 ,4853 ,4943 ,4920 ,4872 ,4882 ,4947 ,4829 ,4819 ,4850 ,4870 ,4879 ,4925 ,4843 ,4848 ,4863 ,4851 ,4918 ,4924 ,4903 ,4938 ,4871 ,4820 ,4844 ,4916 ,4834 ,4924 ,4910 ,4932 ,4844 ,4807 ,4906 ,4907 ,4809 ,4872 ,4927 ,4914 ,4927 ,4838 ,4821 ,4894 ,4907 ,4912 ,4890 ,4851 ,4874 ,4893 ,4896 ,4858 ,4868 ,4946 ,4891 ,4813 ,4832 ,4862 ,4836 ,4893 ,4886 ,4857 ,4863 ,4891 ,4880 ,4803 ,4793 ,4971 ,4914 ,4861 ,4853 ,4888 ,4859 ,4884 ,4785 ,4925 ,4848 ,4926 ,4830 ,4921 ,4878 ,4854 ,4856 ,4884 ,4923 ,4856 ,4845 ,4913 ,4803 ,4872 ,4791 ,4890 ,4841 ,4906 ,4862 ,4862 ,4922 ,4907 ,4845 ,4850 ,4833 ,4928 ,4888 ,4931 ,4864 ,4827 ,4881 ,4893 ,4863 ,4820 ,4890 ,4930 ,4880 ,4863 ,4871 ,4868 ,4939 ,4928 ,4849 ,4832 ,4822 ,4842 ,4839 ,4904 ,4866 ,4902 ,4916 ,4916 ,4866 ,4880 ,4885 ,4932 ,4811 ,4813 ,4801 ,4933 ,4825 ,4928 ,4843 ,4893 ,4894 ,4844 ,4863 ,4900 ,4894 ,4852 ,4889 ,4801 ,4874 ,4857 ,4853 ,4923 ,4826 ,4867 ,4839 ,4864 ,4882 ,4823 ,4813 ,4893 ,4860 ,4887 ,4898 ,4912 ,4892 ,4838 ,4958 ,4897 ,4869 ,4819 ,4898 ,4922 ,4876 ,4860 ,4804 ,4976 ,4896 ,4897 ,4763 ,4907 ,4857 ,4889 ,4911 ,4744 ,4880 ,4874 ,4904 ,4880 ,4910 ,4920 ,4824 ,4890 ,4838 ,4804 ,4825 ,4866 ,4877 ,4866 ,4858 ,4887 ,4933 ,4853 ,4789 ,4857 ,4922 ,4749 ,4839 ,4941 ,4861 ,4938 ,4779 ,4867 ,4902 ,4849 ,4856 ,4922 ,4916 ,4883 ,4792 ,4837 ,4830 ,4848 ,4856 ,4867 ,4938 ,4847 ,4846 ,4881 ,4816 ,4859 ,4896 ,4899 ,4817 ,4850 ,4852 ,4799 ,4875 ,4772 ,4863 ,4862 ,4876 ,4870 ,4926 ,4854 ,4867 ,4766 ,4856 ,4886 ,4935 ,4844 ,4820 ,4921 ,4870 ,4825 ,4885 ,4858 ,4810 ,4807 ,4816 ,4873 ,4856 ,4868 ,4861 ,4885 ,4852 ,4948 ,4943 ,4900 ,4836 ,4891 ,4870 ,4878 ,4852 ,4866 ,4823 ,4882 ,4912 ,4799 ,4887 ,4895 ,4823 ,4844 ,4906 ,4826 ,4859 ,4900 ,4867 ,4891 ,4940 ,4818 ,4795 ,4894 ,4871 ,4826 ,4798 ,4829 ,4798 ,4876 ,4843 ,4872 ,4836 ,4817 ,4781 ,4827 ,4862 ,4851 ,4886 ,4805 ,4848 ,4863 ,4914 ,4811 ,4973 ,4871 ,4854 ,4797 ,4956 ,4848 ,4881 ,4842 ,4862 ,4926 ,4853 ,4779 ,4824 ,4966 ,4854 ,4789 ,4730 ,4848 ,4839 ,4893 ,4903 ,4837 ,4846 ,4875 ,4939 ,4764 ,4859 ,4866 ,4853 ,4820 ,4843 ,4884 ,4836 ,4850 ,4803 ,4935 ,4911 ,4940 ,4937 ,4863 ,4773 ,4866 ,4824 ,4851 ,4828 ,4877 ,4891 ,4892 ,4882 ,4791 ,4849 ,4890 ,4930 ,4851 ,4868 ,4799 ,4838 ,4830 ,4826 ,4838 ,4892 ,4875 ,4866 ,4814 ,4822 ,4814 ,4867 ,4852 ,4791 ,4899 ,4895 ,4827 ,4855 ,4837 ,4846 ,4856 ,4867 ,4848 ,4896 ,4863 ,4899 ,4853 ,4852 ,4901 ,4859 ,4925 ,4833 ,4865 ,4775 ,4834 ,4822 ,4768 ,4868 ,4852 ,4836 ,4887 ,4804 ,4826 ,4905 ,4877 ,4909 ,4905 ,4837 ,4822 ,4822 ,4836 ,4898 ,4853 ,4911 ,4852 ,4797 ,4845 ,4803 ,4798 ,4825 ,4787 ,4909 ,4783 ,4865 ,4912 ,4834 ,4793 ,4903 ,4874 ,4807 ,4920 ,4872 ,4808 ,4809 ,4859 ,4843 ,4826 ,4910 ,4877 ,4783 ,4864 ,4880 ,4894 ,4891 ,4836 ,4835 ,4829 ,4870 ,4866 ,4803 ,4831 ,4846 ,4818 ,4793 ,4865 ,4887 ,4897 ,4876 ,4930 ,4859 ,4828 ,4791 ,4816 ,4796 ,4891 ,4873 ,4863 ,4865 ,4863 ,4793 ,4905 ,4893 ,4788 ,4843 ,4833 ,4775 ,4883 ,4914 ,4788 ,4855 ,4872 ,4836 ,4851 ,4885 ,4788 ,4821 ,4874 ,4909 ,4883 ,4821 ,4834 ,4880 ,4795 ,4882 ,4908 ,4889 ,4842 ,4921 ,4892 ,4842 ,4857 ,4833 ,4835 ,4809 ,4817 ,4873 ,4803 ,4884 ,4941 ,4826 ,4875 ,4815 ,4845 ,4867 ,4763 ,4827 ,4808 ,4896 ,4849 ,4918 ,4803 ,4860 ,4839 ,4849 ,4923 ,4870 ,4881 ,4930 ,4821 ,4835 ,4869 ,4899 ,4842 ,4780 ,4859 ,4829 ,4919 ,4826 ,4920 ,4877 ,4831 ,4936 ,4828 ,4889 ,4835 ,4838 ,4825 ,4859 ,4858 ,4821 ,4870 ,4893 ,4910 ,4833 ,4891 ,4879 ,4980 ,4735 ,4716 ,4856 ,4847 ,4827 ,4866 ,4808 ,4925 ,4844 ,4854 ,4820 ,4791 ,4871 ,4849 ,4873 ,4937 ,4852 ,4877 ,4879 ,4809 ,4845 ,4835 ,4824 ,4796 ,4809 ,4819 ,4903 ,4840 ,4846 ,4843 ,4892 ,4867 ,4913 ,4875 ,4872 ,4811 ,4874 ,4790 ,4849 ,4908 ,4864 ,4759 ,4855 ,4855 ,4856 ,4852 ,4897 ,4781 ,4776 ,4904 ,4875 ,4790 ,4841 ,4849 ,4860 ,4925 ,4775 ,4829 ,4801 ,4818 ,4866 ,4836 ,4815 ,4862 ,4865 ,4837 ,4869 ,4804 ,4837 ,4835 ,4836 ,4840 ,4764 ,4783 ,4883 ,4913 ,4863 ,4826 ,4810 ,4803 ,4737 ,4829 ,4900 ,4795 ,4811 ,4879 ,4817 ,4859 ,4885 ,4875 ,4844 ,4898 ,4875 ,4847 ,4843 ,4786 ,4839 ,4831 ,4824 ,4849 ,4825 ,4851 ,4840 ,4894 ,4841 ,4881 ,4795 ,4876 ,4881 ,4773 ,4895 ,4829 ,4883 ,4870 ,4838 ,4839 ,4877 ,4753 ,4870 ,4777 ,4862 ,4862 ,4934 ,4842 ,4848 ,4809 ,4845 ,4829 ,4835 ,4873 ,4819 ,4814 ,4788 ,4810 ,4826 ,4883 ,4848 ,4857 ,4932 ,4840 ,4818 ,4832 ,4890 ,4811 ,4806 ,4807 ,4901 ,4798 ,4773 ,4853 ,4793 ,4758 ,4850 ,4822 ,4961 ,4789 ,4797 ,4884 ,4760 ,4879 ,4909 ,4790 ,4884 ,4911 ,4824 ,4840 ,4837 ,4841 ,4749 ,4818 ,4891 ,4884 ,4779 ,4973 ,4800 ,4918 ,4825 ,4854 ,4782 ,4880 ,4848 ,4811 ,4872 ,4859 ,4856 ,4769 ,4818 ,4835 ,4815 ,4849 ,4820 ,4822 ,4834 ,4887 ,4844 ,4892 ,4764 ,4804 ,4869 ,4834 ,4858 ,4806 ,4816 ,4772 ,4877 ,4873 ,4812 ,4806 ,4878 ,4766 ,4855 ,4839 ,4852 ,4811 ,4823 ,4789 ,4856 ,4814 ,4915 ,4857 ,4798 ,4900 ,4851 ,4848 ,4865 ,4756 ,4873 ,4815 ,4855 ,4829 ,4878 ,4886 ,4798 ,4797 ,4822 ,4854 ,4859 ,4897 ,4823 ,4809 ,4925 ,4849 ,4818 ,4772 ,4819 ,4851 ,4813 ,4864 ,4855 ,4843 ,4823 ,4795 ,4878 ,4862 ,4880 ,4818 ,4839 ,4864 ,4791 ,4808 ,4815 ,4874 ,4848 ,4814 ,4767 ,4810 ,4913 ,4804 ,4878 ,4809 ,4795 ,4832 ,4835 ,4864 ,4858 ,4843 ,4874 ,4831 ,4738 ,4887 ,4816 ,4887 ,4851 ,4795 ,4803 ,4857 ,4838 ,4830 ,4857 ,4842 ,4824 ,4829 ,4806 ,4859 ,4820 ,4884 ,4757 ,4901 ,4815 ,4769 ,4834 ,4817 ,4808 ,4833 ,4825 ,4880 ,4754 ,4813 ,4838 ,4858 ,4832 ,4791 ,4811 ,4860 ,4762 ,4832 ,4880 ,4790 ,4881 ,4787 ,4835 ,4852 ,4876 ,4843 ,4849 ,4808 ,4804 ,4850 ,4699 ,4881 ,4878 ,4793 ,4790 ,4800 ,4839 ,4865 ,4842 ,4771 ,4836 ,4795 ,4857 ,4771 ,4863 ,4804 ,4807 ,4813 ,4813 ,4867 ,4861 ,4899 ,4859 ,4868 ,4784 ,4828 ,4903 ,4847 ,4775 ,4888 ,4810 ,4792 ,4779 ,4925 ,4839 ,4849 ,4847 ,4818 ,4873 ,4838 ,4832 ,4759 ,4874 ,4768 ,4785 ,4912 ,4844 ,4775 ,4751 ,4814 ,4885 ,4881 ,4879 ,4822 ,4780 ,4847 ,4767 ,4824 ,4768 ,4814 ,4830 ,4848 ,4841 ,4860 ,4833 ,4787 ,4810 ,4862 ,4871 ,4831 ,4847 ,4828 ,4916 ,4779 ,4805 ,4818 ,4843 ,4772 ,4818 ,4819 ,4790 ,4803 ,4901 ,4819 ,4745 ,4830 ,4841 ,4894 ,4833 ,4851 ,4800 ,4829 ,4740 ,4807 ,4870 ,4846 ,4919 ,4804 ,4865 ,4752 ,4889 ,4856 ,4801 ,4892 ,4718 ,4768 ,4802 ,
};

int size = 0;
int primes[SegmentLen]; 

bool IsPrime( int x ) {
     
     if ( x == 2 ) return true ;  
     
     for ( int i = 2 ; i * i <= x ; i++ )
     { 
         if ( x % i == 0 ) return false ;
     }
     
     return true ;
     
}

void id0( int x ) {
     
     for ( int i = 2 ; i <= x ; i++ )
     {
         if ( IsPrime(i) ){
               size++;
               primes[size] = i;
               

         }
     }
     
}
         

bool good( int x ){
     
     if ( x == 1 ) return false;
     
     if ( x != 2 && x % 4 != 1 ) return false;
     
     for ( int i = 1 ; primes[i] * primes[i] <= x ; i++ ) {
         if ( x % primes[i] == 0 ) return false ;
     }
     
     return true ;
     
} 

int main( void ){
    
    int l , r , T ;
    int ans = 0; 
    
   

    
    id0( 33000 );
    
   

   

        
    
        cin >> l >> r ;
    
        while ( l % SegmentLen != 1 && l <= r )
        {
              if ( good( l ) ) ans++;
              l++;
        }
    
        if( l > r ) 
        {
            cout << ans << endl;
            

            return 0; 
        }
    
        while( r % SegmentLen != 0 && l <= r )
        {
            if ( good( r ) ) ans++;
            r--;
        }
    
        if( l > r ) {
        cout << ans << endl;
        

        return 0; 
        }
    
        int ll = ( l / SegmentLen ) + 1;
        int rr = ( r / SegmentLen ) ;
    
         for ( int i = ll ; i <= rr ; i++ ) ans += Precalculated[i] ;
    
         cout << ans << endl;
         
    

    
    return 0; 
    
}
    
