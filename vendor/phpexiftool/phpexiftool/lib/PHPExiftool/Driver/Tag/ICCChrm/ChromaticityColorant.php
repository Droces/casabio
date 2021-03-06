<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\ICCChrm;

use PHPExiftool\Driver\AbstractTag;

class ChromaticityColorant extends AbstractTag
{

    protected $Id = 10;

    protected $Name = 'ChromaticityColorant';

    protected $FullName = 'ICC_Profile::Chromaticity';

    protected $GroupName = 'ICC-chrm';

    protected $g0 = 'ICC_Profile';

    protected $g1 = 'ICC-chrm';

    protected $g2 = 'Image';

    protected $Type = 'int16u';

    protected $Writable = false;

    protected $Description = 'Chromaticity Colorant';

    protected $Values = array(
        1 => array(
            'Id' => 1,
            'Label' => 'ITU-R BT.709',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'SMPTE RP145-1994',
        ),
        3 => array(
            'Id' => 3,
            'Label' => 'EBU Tech.3213-E',
        ),
        4 => array(
            'Id' => 4,
            'Label' => 'P22',
        ),
    );

}
